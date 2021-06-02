#include "../minirt.h"

#define EPSILON 0.0001

double	get_shadow(t_vector ray, t_vector p, t_scene *scene)
{
	double		i_d;
	double		min_d;
	t_lobject	*shape;
	double		(*hit_shape[5])(t_vector ray, t_vector origin, void *object);

	intersection_initialization(hit_shape);
	shape = scene->objs;
	min_d = hit_shape[shape->type](ray, sum_vectors(p,
				vector_x_alpha(ray, EPSILON)), shape->obj);
	while (shape->next)
	{
		shape = shape->next;
		i_d = hit_shape[shape->type](ray, sum_vectors(p,
					vector_x_alpha(ray, EPSILON)), shape->obj);
		if ((i_d < min_d || min_d < 0) && i_d > 0)
			min_d = i_d;
	}
	return (min_d);
}

void	get_shadow2(t_vector ray, t_scene *scene, t_light_shadow *shadow)
{
	while (shadow->list)
	{
		shadow->light_ray = normalized_v(substraction_vectors(
					((t_light *)shadow->list->obj)->light_point, ray));
		shadow->d_light_i = get_shadow(shadow->light_ray, ray, scene);
		if (shadow->d_light_i < 0 || (shadow->d_light_i) > def_len_of_v(
				substraction_vectors(((
							t_light *)shadow->list->obj)->light_point, ray)))
		{
			shadow->light_v = v_dot_product(shadow->norm_shape, normalized_v(
						substraction_vectors(((t_light *)
								(shadow->list->obj))->light_point, ray)));
			shadow->tmp_rgb = colour_addition(shadow->tmp_rgb,
					diffuse_light(shadow->rgb, (t_light *)(shadow->list->obj),
						shadow->light_v));
		}
		shadow->list = shadow->list->next;
	}
}

t_colour_op	get_shadow1(t_vector ray, t_scene *scene, t_lobject *current_shape)
{
	t_light_shadow	shadow;
	t_vector		(*get_norm[5])(t_vector, t_lobject *, t_colour_op *,
					t_vector);

	shadow.list = scene->lights;
	shadow.rgb = scene->background_colour;
	if (current_shape == NULL)
		return (shadow.rgb);
	g_normal_initialization(get_norm);
	shadow.norm_shape = get_norm[current_shape->type](ray, current_shape,
			&shadow.rgb, ((t_camera *)(scene->cameras->obj))->origin);
	shadow.tmp_rgb = ambient_light(shadow.rgb, scene->ambient);
	get_shadow2(ray, scene, &shadow);
	shadow.rgb = shadow.tmp_rgb;
	return (shadow.rgb);
}
