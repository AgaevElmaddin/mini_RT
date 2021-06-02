#ifndef RAY_H
# define RAY_H

typedef struct s_window_view
{
	double		width;
	double		height;
	double		pixel_x;
	double		pixel_y;
}				t_window_view;

typedef struct s_bary
{
	double	t;
	double	u;
	double	v;
}				t_bary;

typedef struct s_check
{
	double	check1;
	double	check2;
}				t_check;

double	ray_and_sphere_intersection(t_vector ray_direction, t_vector ray_origin,
			void *sphere);
double	ray_and_triangle_intersection(t_vector ray_dir, t_vector ray_origin,
			void *triangle);
double	ray_and_plane_intersection(t_vector ray_direction, t_vector ray_origin,
			void *plane);
double	ray_and_cylinder_intersection(t_vector ray_direction,
			t_vector ray_origin, void *cylinder);
double	different_conditions(double x1, double x2, t_check f,
			t_cylinder *cylinder);
double	ray_and_square_intersection(t_vector ray_direction, t_vector ray_origin,
			void *square);

#endif
