#include "../minirt.h"

void	create_scene(t_scene *scene)
{
	t_lobject	*camera;
	int			r_x;
	int			r_y;

	if (!scene->viewport)
		different_errors("Something wrong with scene. Try again!");
	mlx_get_screen_size(scene->mlx.mlx, &r_x, &r_y);
	if (scene->viewport->width > r_x)
		scene->viewport->width = r_x;
	if (scene->viewport->height > r_y)
		scene->viewport->height = r_y;
	camera = scene->cameras;
	if (camera)
	{
		while (camera->next)
			camera = camera->next;
		camera->next = scene->cameras;
	}
}
