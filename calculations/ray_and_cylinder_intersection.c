#include "../minirt.h"

double	different_conditions(double x1, double x2, t_check f,
		t_cylinder *cylinder)
{
	if (x1 < x2)
	{
		if (f.check1 >= 0 && f.check1 <= cylinder->height && x1 >= 0)
			return (x1);
		else if (f.check2 >= 0 && f.check2 <= cylinder->height && x2 >= 0)
			return (x2);
	}
	else if (x1 > x2)
	{
		if (f.check2 >= 0 && f.check2 <= cylinder->height && x2 >= 0)
			return (x2);
		else if (f.check1 >= 0 && f.check1 <= cylinder->height && x1 >= 0)
			return (x1);
	}
	return (-1);
}

static	double	intersection_points(void *cylinder, t_vector ray_direction,
				double t, t_vector ao)
{
	t_cylinder	*cylinder1;
	double		f;

	cylinder1 = (t_cylinder *)cylinder;
	f = v_dot_product(ray_direction, normalized_v(cylinder1->orientation)
			) * t + v_dot_product(ao,
			normalized_v(cylinder1->orientation));
	return (f);
}

double	ray_and_cylinder_intersection(t_vector ray_direction,
		t_vector ray_origin, void *cylinder)
{
	t_number	n;
	double		discriminant;
	t_vector	ao;
	t_check		f;
	t_cylinder	*cylinder1;

	cylinder1 = (t_cylinder *)cylinder;
	n.coeff.a = v_dot_product(ray_direction, ray_direction) - pow(v_dot_product(
				ray_direction, normalized_v(cylinder1->orientation)), 2);
	ao = substraction_vectors(ray_origin, cylinder1->a);
	n.coeff.b = 2 * (v_dot_product(ray_direction, ao) - v_dot_product(
				ray_direction, normalized_v(cylinder1->orientation))
			* v_dot_product(ao, normalized_v(cylinder1->orientation)));
	n.coeff.c = v_dot_product(ao, ao) - pow(v_dot_product(ao, normalized_v(
					cylinder1->orientation)), 2)
		- pow(cylinder1->diameter / 2, 2);
	discriminant = n.coeff.b * n.coeff.b - 4 * n.coeff.a * n.coeff.c;
	if (discriminant < 0)
		return (-1);
	n.root.t1 = (-n.coeff.b - sqrt(discriminant)) / (2 * n.coeff.a);
	n.root.t2 = (-n.coeff.b + sqrt(discriminant)) / (2 * n.coeff.a);
	f.check1 = intersection_points(cylinder, ray_direction, n.root.t1, ao);
	f.check2 = intersection_points(cylinder, ray_direction, n.root.t2, ao);
	return (different_conditions(n.root.t1, n.root.t2, f, cylinder1));
}
