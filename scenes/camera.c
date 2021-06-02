#include "../minirt.h"

t_camera	*create_camera(t_vector origin, t_vector direction, int fov)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		different_errors("Can't allocate memory for camera");
	camera->origin = origin;
	camera->direction = direction;
	camera->fov = fov;
	return (camera);
}
