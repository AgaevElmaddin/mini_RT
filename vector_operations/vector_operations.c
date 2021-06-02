#include "../minirt.h"

t_vector	create_vector(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector	sum_vectors(t_vector v1, t_vector v2)
{
	t_vector	sum;

	sum = create_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (sum);
}

t_vector	substraction_vectors(t_vector v1, t_vector v2)
{
	t_vector	sub;

	sub = create_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	return (sub);
}

double	def_len_of_v(t_vector v)
{
	double	len_v;

	len_v = sqrt(v.x * v.x + v.y *v.y + v.z * v.z);
	return (len_v);
}

t_vector	normalized_v(t_vector v)
{
	double	len_v;

	len_v = def_len_of_v(v);
	v.x /= len_v;
	v.y /= len_v;
	v.z /= len_v;
	return (v);
}
