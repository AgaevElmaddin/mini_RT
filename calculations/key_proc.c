#include "../minirt.h"

int	exit_program(void)
{
	exit(0);
	return (0);
}

int	key_proc(int key, t_scene *scene)
{
	if (key == 53)
		exit_program();
	if (key == 49 && scene->cameras && scene->cameras->next)
		scene->cameras = scene->cameras->next;
	rendering(scene);
	mlx_clear_window(scene->mlx.mlx, scene->mlx.window);
	mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.window,
		scene->mlx.image, 0, 0);
	return (0);
}
