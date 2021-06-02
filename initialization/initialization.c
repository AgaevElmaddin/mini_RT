#include "../minirt.h"

void	mlx_initialization(t_scene *scene)
{
	scene->mlx.bpp = 0;
	scene->mlx.len_line = 0;
	scene->mlx.mlx = mlx_init();
	scene->mlx.window = mlx_new_window(scene->mlx.mlx,
			scene->viewport->width, scene->viewport->height, "miniRT");
	scene->mlx.image = mlx_new_image(scene->mlx.mlx,
			scene->viewport->width, scene->viewport->height);
	scene->mlx.data = mlx_get_data_addr(scene->mlx.image,
			&(scene->mlx.bpp), &(scene->mlx.len_line), &(scene->mlx.endian));
}

void	scene_initialization(t_scene *scene)
{
	scene->viewport = NULL;
	scene->ambient = NULL;
	scene->cameras = NULL;
	scene->objs = NULL;
	scene->lights = NULL;
	scene->background_colour = create_colour(0, 0, 0);
}

void	intersection_initialization(double (*hit_obj[5]) (t_vector ray_origin,
t_vector ray_direction, void *object))
{
	hit_obj[SPHERE] = &ray_and_sphere_intersection;
	hit_obj[PLANE] = &ray_and_plane_intersection;
	hit_obj[SQUARE] = &ray_and_square_intersection;
	hit_obj[CYLINDER] = &ray_and_cylinder_intersection;
	hit_obj[TRIANGLE] = &ray_and_triangle_intersection;
}

void	g_normal_initialization(t_vector (*get_norm[5]) (t_vector p,
		t_lobject *shape, t_colour_op *rgb, t_vector ray_origin))
{
	get_norm[SPHERE] = &sphere_normal;
	get_norm[PLANE] = &plane_normal;
	get_norm[SQUARE] = &square_normal;
	get_norm[CYLINDER] = &cylinder_normal;
	get_norm[TRIANGLE] = &triangle_normal;
}
