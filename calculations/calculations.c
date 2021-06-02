#include "../minirt.h"

void	put_new_pixel(t_mlx *mlx, int j, int i, t_colour_op rgb)
{
	int		tmp_rgb;
	char	*dst;

	tmp_rgb = create_trgb(rgb);
	dst = mlx->data + (i * mlx->len_line + j * (mlx->bpp / 8));
	if (dst)
		*(unsigned int *)dst = tmp_rgb;
}

t_vector	camera_matrix(t_scene *scene, int i, int j)
{
	t_cm		cm;
	t_vector	matrix[3];

	matrix[0] = normalized_v(vector_x_alpha(((t_camera *)
					(scene->cameras->obj))->direction, -1));
	matrix[1] = normalized_v(vector_x_alpha(cross_product(normalized_v(
						create_vector(0, -1, 0)), matrix[0]), -1));
	matrix[2] = normalized_v(vector_x_alpha(cross_product(matrix[0],
					matrix[1]), -1));
	cm.viewport_x = (j / (double)scene->viewport->width) - 0.5;
	cm.viewport_y = 0.5 - (i / (double)scene->viewport->height);
	cm.aspect = (double)scene->viewport->width / (double)scene->viewport->height;
	if (cm.aspect > 1)
		cm.viewport_x *= cm.aspect;
	else if (cm.aspect < 1)
		cm.viewport_y /= cm.aspect;
	cm.viewport_x *= tan((((t_camera *)
					(scene->cameras->obj))->fov / 2) *M_PI / 180);
	cm.viewport_y *= tan((((t_camera *)
					(scene->cameras->obj))->fov / 2) *M_PI / 180);
	cm.res = sum_vectors(vector_x_alpha(matrix[1], cm.viewport_x),
			vector_x_alpha(matrix[2], cm.viewport_y));
	cm.res = substraction_vectors(cm.res, matrix[0]);
	cm.res = normalized_v(cm.res);
	return (cm.res);
}

t_vector	intersection(t_vector ray, t_scene *scene, t_lobject **current_obj)
{
	t_vector	res;
	double		i_d;
	double		min_d;
	t_lobject	*shape;
	double		(*hit_shape[5])(t_vector ray, t_vector origin, void *object);

	intersection_initialization(hit_shape);
	shape = scene->objs;
	min_d = hit_shape[shape->type](ray, ((t_camera *)
				(scene->cameras->obj))->origin, shape->obj);
	if (min_d > 0)
		*current_obj = shape;
	while (shape->next)
	{
		shape = shape->next;
		i_d = hit_shape[shape->type](ray, ((t_camera *)
					(scene->cameras->obj))->origin, shape->obj);
		if ((i_d < min_d || min_d < 0) && i_d > 0)
		{
			min_d = i_d;
			*current_obj = shape;
		}
	}
	res = vector_x_alpha(ray, min_d);
	return (res);
}

void	rendering(t_scene *scene)
{
	t_colour_op	rgb;
	t_vector	ray;
	t_lobject	*current_shape;
	int			i;
	int			j;

	i = -1;
	while (++i < scene->viewport->height)
	{
		j = -1;
		while (++j < scene->viewport->width)
		{
			current_shape = NULL;
			rgb = scene->background_colour;
			if (scene->cameras && scene->objs)
			{
				ray = camera_matrix(scene, i, j);
				ray = intersection(ray, scene, &current_shape);
				rgb = get_shadow1(sum_vectors(ray, ((t_camera *)
								scene->cameras->obj)->origin),
						scene, current_shape);
			}
			put_new_pixel(&scene->mlx, j, i, rgb);
		}
	}
}
