#include "../minirt.h"

double	min_non_negative_double(double x1, double x2)
{
	if (x1 < 0 && x2 < 0)
		return (-1);
	if (x1 < 0 && x2 > 0)
		return (x2);
	if (x1 > 0 && x2 < 0)
		return (x1);
	if (x1 > x2)
		return (x2);
	else
		return (x1);
	return (-1);
}

double	ray_and_sphere_intersection(t_vector ray_direction, t_vector ray_origin,
		void *sphere)
{
	t_coeff		coeff;
	double		discriminant;
	t_root		root;
	t_vector	s;
	t_sphere	*sphere1;

	root.t1 = 0;
	root.t2 = 0;
	sphere1 = (t_sphere *)sphere;
	s = substraction_vectors(ray_origin, sphere1->center);
	coeff.b = 2 * v_dot_product(s, ray_direction);
	coeff.c = v_dot_product(s, s)
		- sphere1->diameter / 2 * sphere1->diameter / 2;
	discriminant = coeff.b * coeff.b - 4 * coeff.c;
	if (discriminant < 0)
		return (-1);
	root.t1 = (-coeff.b - sqrt(discriminant)) / 2;
	root.t2 = (-coeff.b + sqrt(discriminant)) / 2;
	return (min_non_negative_double(root.t1, root.t2));
}
