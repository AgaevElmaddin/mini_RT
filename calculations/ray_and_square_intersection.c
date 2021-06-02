#include "../minirt.h"

double	ray_and_square_intersection(t_vector ray_direction, t_vector ray_origin,
						void *square)
{
	t_fraction	f;
	t_vector	oc;
	t_vector	point_of_intersect;
	double		side;
	t_square	*square1;

	square1 = (t_square *)square;
	oc = substraction_vectors(ray_origin, square1->center);
	f.denominator = v_dot_product(ray_direction,
			normalized_v(square1->orientation));
	f.numerator = v_dot_product(oc, normalized_v(square1->orientation));
	if (f.denominator == 0 || (f.denominator < 0 && f.numerator < 0)
		|| (f.denominator > 0 && f.numerator > 0))
		return (-1);
	f.fraction = -f.numerator / f.denominator;
	point_of_intersect = substraction_vectors(sum_vectors(vector_x_alpha(
					ray_direction, f.fraction), ray_origin), square1->center);
	side = square1->side / 2;
	if (fabs(point_of_intersect.x) > side || fabs(point_of_intersect.y) > side
		|| fabs(point_of_intersect.z) > side)
		return (-1);
	if (f.fraction > 0)
		return (f.fraction);
	return (-1);
}
