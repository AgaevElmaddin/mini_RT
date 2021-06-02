#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;
	int		fd;

	input_validation(argc, argv, &fd);
	scene_initialization(&scene);
	get_file(&scene, fd);
	mlx_initialization(&scene);
	rendering(&scene);
	if (argc == 2)
	{
		mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.window,
			scene.mlx.image, 0, 0);
		mlx_hook(scene.mlx.window, 2, 0, key_proc, &scene);
		mlx_hook(scene.mlx.window, 17, 1L << 17, exit_program, 0);
		mlx_loop(scene.mlx.mlx);
	}
	else if (argc == 3 && scene.mlx.data)
		save_bmp_file(scene);
	return (0);
}
