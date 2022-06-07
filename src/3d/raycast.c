#include "raycast.h"

#include "../util.h"

#include <math.h>

#define RENDER_DISTANCE 4

double cast_horz(double x, double y, double th);
double cast_vert(double x, double y, double th);

double cast_ray(double x, double y, double th) {
	double horz_dist = HUGE_VAL;
	double vert_dist = HUGE_VAL;

	if (th != 0 && th != PI) {
		horz_dist = cast_horz(x, y, th);
	}
	
	if (th != (PI / 2) && th != (3 * PI / 2)) {
		vert_dist = cast_vert(x, y, th);
	}

	return horz_dist > vert_dist ? vert_dist : horz_dist;
}

double cast_horz(double x, double y, double th) {
	int vdir = th > PI ? 1 : -1;
	double cy = scale_down(x);

	int target_cy = (vdir == 1) ? ceil(cy) : floor(cy);

	return HUGE_VAL;
}

double cast_vert(double x, double y, double th) {
	return HUGE_VAL;
}
