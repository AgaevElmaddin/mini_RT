#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	t_vector	origin;
	t_vector	direction;
	int			fov;
}				t_camera;

t_camera	*create_camera(t_vector origin, t_vector direction, int fov);

#endif
