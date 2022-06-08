#ifndef RC_3D_RAYCAST_H
#define RC_3D_RAYCAST_H

typedef enum {
	HORZ,
	VERT
} ray_type;

double cast_ray(double x, double y, double th, ray_type *type);

#endif // RC_3D_RAYCAST_H
