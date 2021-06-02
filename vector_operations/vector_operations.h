#ifndef VECTOR_OPERATIONS_H
# define VECTOR_OPERATIONS_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

t_vector	create_vector(double x, double y, double z);
t_vector	sum_vectors(t_vector v1, t_vector v2);
t_vector	substraction_vectors(t_vector v1, t_vector v2);
double		def_len_of_v(t_vector v);
t_vector	normalized_v(t_vector v);
double		v_dot_product(t_vector v1, t_vector v2);
t_vector	cross_product(t_vector v1, t_vector v2);
t_vector	vector_x_alpha(t_vector v1, double alpha);

#endif
