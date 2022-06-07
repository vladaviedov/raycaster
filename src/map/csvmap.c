#include "csvmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEARCH_BUF 32
#define DATA_BUF 32

#define META "[meta]\n"
#define META_NAME "name"
#define META_SIZE "size"

#define PLAYER "[player]\n"
#define PLAYER_SPAWN "spawn"

#define WALLS "[walls]\n"
#define WALLS_HWALL "hwall"
#define WALLS_VWALL "vwall"

int find_header(FILE *fp, const char *header);

int csv_load_meta(FILE *fp, csv_meta *buf) {
	if (find_header(fp, META) < 0) {
		return -1;
	}

	memset(buf, 0, sizeof(csv_meta));

	char data[DATA_BUF];
	while (fgets(data, DATA_BUF, fp) != NULL) {
		char *param = strtok(data, ",");
		char *value;
		if (strcmp(param, META_NAME) == 0) {
			value = strtok(NULL, ",");
			if (value == NULL) {
				return -1;
			}

			buf->name = strdup(value);
		}
		if (strcmp(param, META_SIZE) == 0) {
			value = strtok(NULL, ",");
			if (value == NULL) {
				return -1;
			}
			buf->sizex = atoi(value);

			value = strtok(NULL, ",");
			if (value == NULL) {
				return -1;
			}
			buf->sizey = atoi(value);
		}
	}

	if (buf->name == NULL || buf->sizex == 0 || buf->sizey == 0) {
		return -1;
	}

	return 0;
}

int csv_load_player(FILE *fp, csv_player *buf) {
	if (find_header(fp, PLAYER) < 0) {
		return -1;
	}

	memset(buf, 0, sizeof(csv_player));

	char data[DATA_BUF];
	while (fgets(data, DATA_BUF, fp) != NULL) {
		char *param = strtok(data, ",");
		char *value;
		if (strcmp(param, PLAYER_SPAWN) == 0) {
			value = strtok(NULL, ",");
			if (value == NULL) {
				return -1;
			}
			buf->spawnx = atoi(value);

			value = strtok(NULL, ",");
			if (value == NULL) {
				return -1;
			}
			buf->spawny = atoi(value);
		} 
	}

	return 0;
}

int csv_goto_walls(FILE *fp) {
	if (find_header(fp, WALLS) < 0) {
		return -1;
	}

	return 0;
}

int csv_next_wall(FILE *fp, csv_wall *buf) {
	memset(buf, 0, sizeof(csv_wall));

	char data[DATA_BUF];
	if (fgets(data, DATA_BUF, fp) == NULL) {
		return -1;
	}

	char *param = strtok(data, ",");
	if (strcmp(param, WALLS_HWALL) == 0) {
		buf->type = HWALL;
	} else if (strcmp(param, WALLS_VWALL) == 0) {
		buf->type = VWALL;
	} else {
		return -1;
	}

	char *value = strtok(NULL, ",");
	buf->startx = atoi(value);
	value = strtok(NULL, ",");
	buf->starty = atoi(value);
	value = strtok(NULL, ",");
	buf->length = atoi(value);
	return 0;
}

/* Internal */

int find_header(FILE *fp, const char *header) {
	fseek(fp, 0, SEEK_SET);
	char temp[SEARCH_BUF];
	while (fgets(temp, SEARCH_BUF, fp) != NULL) {
		if (strncmp(temp, header, SEARCH_BUF) == 0) {
			return 0;
		}
	}

	return -1;
}
