#ifndef OBJECTS_NORMAL_H
# define OBJECTS_NORMAL_H

t_vector	sphere_normal(t_vector p, t_lobject *shape,
				t_colour_op *rgb, t_vector ray_origin);
t_vector	plane_normal(t_vector p, t_lobject *shape,
				t_colour_op *rgb, t_vector ray_origin);
t_vector	triangle_normal(t_vector p, t_lobject *shape,
				t_colour_op *rgb, t_vector ray_origin);
t_vector	square_normal(t_vector p, t_lobject *shape,
				t_colour_op *rgb, t_vector ray_origin);
t_vector	cylinder_normal(t_vector p, t_lobject *shape,
				t_colour_op *rgb, t_vector ray_origin);

#endif
