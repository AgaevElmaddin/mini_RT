#include "../minirt.h"

double	v_dot_product(t_vector v1, t_vector v2)
{
	double	dot_product;

	dot_product = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dot_product);
}

t_vector	cross_product(t_vector v1, t_vector v2)
{
	double	x;
	double	y;
	double	z;

	x = v1.y * v2.z - v1.z * v2.y;
	y = v1.z * v2.x - v1.x * v2.z;
	z = v1.x * v2.y - v1.y * v2.x;
	return (create_vector(x, y, z));
}

t_vector	vector_x_alpha(t_vector v1, double alpha)
{
	double	x;
	double	y;
	double	z;

	x = alpha * v1.x;
	y = alpha * v1.y;
	z = alpha * v1.z;
	return (create_vector(x, y, z));
}
