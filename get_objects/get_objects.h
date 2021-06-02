#ifndef GET_OBJECTS_H
# define GET_OBJECTS_H

t_light		*get_ambient(char **str);
t_camera	*get_camera(char **str);
t_canvas	*get_resolution(char **str);
t_light		*get_light(char **str);
t_sphere	*get_sphere(char **str);
t_plane		*get_plane(char **str);
t_square	*get_square(char **str);
t_cylinder	*get_cylinder(char **str);
t_triangle	*get_triangle(char **str);

#endif
