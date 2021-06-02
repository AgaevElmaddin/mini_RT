#include "../minirt.h"

#define EPSILON 0.000001

static	void	triangles_sides(t_vector ray_origin, void *triangle,
				t_side *side)
{
	t_triangle		*tr1;

	tr1 = (t_triangle *)triangle;
	side->ov0 = substraction_vectors(ray_origin, tr1->first_point);
	side->v1v0 = substraction_vectors(tr1->second_point, tr1->first_point);
	side->v2v0 = substraction_vectors(tr1->third_point, tr1->first_point);
}

double	ray_and_triangle_intersection(t_vector ray_dir, t_vector ray_origin,
			void *triangle)
{
	t_bary			bary;
	t_side			side;
	t_det			n;
	t_cross_product	c;
	t_triangle		*tr1;

	tr1 = (t_triangle *)triangle;
	triangles_sides(ray_origin, tr1, &side);
	c.cross_ray_dir_v2v0 = cross_product(ray_dir, side.v2v0);
	n.det = v_dot_product(cross_product(side.v2v0, side.v1v0), ray_dir);
	if (n.det > -EPSILON && n.det < EPSILON)
		return (-1);
	n.det_pow_minus_1 = pow(n.det, -1);
	side.ov0 = substraction_vectors(ray_origin, tr1->first_point);
	bary.u = v_dot_product(c.cross_ray_dir_v2v0, side.ov0) * n.det_pow_minus_1;
	if (bary.u < 0.0 || bary.u > 1.0)
		return (-1);
	c.cross_ray_ov0_v1v0 = cross_product(side.ov0, side.v1v0);
	bary.v = v_dot_product(c.cross_ray_ov0_v1v0, ray_dir) * n.det_pow_minus_1;
	if (bary.v < 0.0 || bary.u + bary.v > 1.0)
		return (-1);
	bary.t = v_dot_product(c.cross_ray_ov0_v1v0, side.v2v0) * n.det_pow_minus_1;
	if (bary.t > 0)
		return (bary.t);
	return (-1);
}
