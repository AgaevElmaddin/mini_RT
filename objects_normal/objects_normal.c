#include "../minirt.h"

t_vector	sphere_normal(t_vector p, t_lobject *shape,
			t_colour_op *rgb, t_vector ray_origin)
{
	t_vector	normal;
	t_sphere	*sphere1;

	(void)ray_origin;
	sphere1 = (t_sphere *)shape->obj;
	*rgb = sphere1->rgb;
	normal = substraction_vectors(p, sphere1->center);
	normalized_v(normal);
	return (normal);
}

t_vector	plane_normal(t_vector p, t_lobject *shape,
			t_colour_op *rgb, t_vector ray_origin)
{
	t_vector	normal;
	t_plane		*plane1;

	(void)p;
	plane1 = (t_plane *)shape->obj;
	*rgb = plane1->rgb;
	normal = plane1->orientation;
	normal = normalized_v(normal);
	if (v_dot_product(normal, normalized_v(substraction_vectors(
					p, ray_origin))) < 0)
		return (normal);
	return ((vector_x_alpha(normal, -1)));
}

t_vector	triangle_normal(t_vector p, t_lobject *shape,
			t_colour_op *rgb, t_vector ray_origin)
{
	t_vector	a;
	t_vector	b;
	t_vector	normal;
	t_triangle	*triangle1;

	(void)p;
	triangle1 = (t_triangle *)shape->obj;
	*rgb = triangle1->rgb;
	a = substraction_vectors(triangle1->second_point, triangle1->first_point);
	b = substraction_vectors(triangle1->third_point, triangle1->first_point);
	normal = cross_product(a, b);
	normal = normalized_v(normal);
	if (v_dot_product(normal, normalized_v(substraction_vectors(
					p, ray_origin))) < 0)
		return (normal);
	return (vector_x_alpha(normal, -1));
}

t_vector	square_normal(t_vector p, t_lobject *shape,
			t_colour_op *rgb, t_vector ray_origin)
{
	t_vector	normal;
	t_square	*square1;

	(void)p;
	square1 = (t_square *)shape->obj;
	*rgb = square1->rgb;
	normal = square1->orientation;
	normal = normalized_v(normal);
	if (v_dot_product(normal, normalized_v(substraction_vectors(
					p, ray_origin))) < 0)
		return (normal);
	return ((vector_x_alpha(normal, -1)));
}

t_vector	cylinder_normal(t_vector p, t_lobject *shape,
			t_colour_op *rgb, t_vector ray_origin)
{
	double		m;
	t_vector	n;
	t_vector	ray_direction;
	double		len_ray_direction;
	t_cylinder	*cylinder1;

	len_ray_direction = def_len_of_v(substraction_vectors(ray_origin, p));
	ray_direction = normalized_v(substraction_vectors(p, ray_origin));
	cylinder1 = (t_cylinder *)shape->obj;
	*rgb = cylinder1->rgb;
	m = (v_dot_product(ray_direction, normalized_v(cylinder1->orientation))
			* len_ray_direction) + v_dot_product(
			substraction_vectors(ray_origin,
				cylinder1->a), normalized_v(cylinder1->orientation));
	n = normalized_v(substraction_vectors(substraction_vectors(p, cylinder1->a),
				vector_x_alpha(normalized_v(cylinder1->orientation), m)));
	if (v_dot_product(ray_direction, n) < 0)
		return (n);
	return (vector_x_alpha(n, -1));
}
