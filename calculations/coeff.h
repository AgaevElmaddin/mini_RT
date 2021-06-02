#ifndef COEFF_H
# define COEFF_H

typedef struct s_coeff
{
	double	a;
	double	b;
	double	c;
}				t_coeff;

typedef struct s_root
{
	double	t1;
	double	t2;
}				t_root;

typedef struct s_fraction
{
	double	numerator;
	double	denominator;
	double	fraction;
}				t_fraction;

typedef struct s_side
{
	t_vector	v1v0;
	t_vector	v2v0;
	t_vector	ov0;
}				t_side;

typedef struct s_number
{
	t_root	root;
	t_coeff	coeff;
}				t_number;

typedef struct s_det
{
	double	det;
	double	det_pow_minus_1;
}				t_det;

typedef struct s_cross_product
{
	t_vector	cross_ray_dir_v2v0;
	t_vector	cross_ray_ov0_v1v0;
}				t_cross_product;

typedef struct s_cm
{
	t_vector	res;
	double		viewport_x;
	double		viewport_y;
	double		aspect;
}				t_cm;

#endif
