#ifndef RC_3D_RAYCAST_H
#define RC_3D_RAYCAST_H

#include "../map/map.h"

typedef enum {
	HORZ,
	VERT
} ray_type;

typedef struct {
	ray_type type;
	mp_cell_val hit_result;
	double distance;
} ray_result;

ray_result cast_ray(double x, double y, double th);

#endif // RC_3D_RAYCAST_H
