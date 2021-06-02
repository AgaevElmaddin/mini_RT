#include "../minirt.h"

#define EPSILON 0.000001

double	ray_and_plane_intersection(t_vector ray_direction, t_vector ray_origin,
		void *plane)
{
	double		denominator;
	t_vector	op0;
	double		t;
	t_plane		*plane1;
	double		numerator;

	plane1 = (t_plane *)plane;
	denominator = v_dot_product(plane1->orientation, ray_direction);
	op0 = substraction_vectors(ray_origin, plane1->p0);
	numerator = v_dot_product(op0, plane1->orientation);
	t = -numerator / denominator;
	if (denominator == 0 || (numerator > 0 && denominator > 0)
		|| (numerator < 0 && denominator < 0))
		return (-1);
	if (t < 0)
		return (-1);
	return (t);
}
