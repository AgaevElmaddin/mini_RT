#include "../minirt.h"

t_cylinder	*get_cylinder(char **str)
{
	char		*message;
	t_vector	a;
	t_vector	orientation;
	t_d_and_h	d_and_h;
	t_colour_op	rgb;

	message = "According to the subject Cylinder format:"
		"(cy),  (x,y,z coordinates),  (normal),  (diameter)  (height)  (rgb)";
	if (number_of_words(str) != 6)
		different_errors(message);
	get_coordinates(&(a), str[1], message);
	get_coordinates(&(orientation), str[2], message);
	normalized_v(orientation);
	d_and_h.diameter = ft_atoi_fractional(str[3]);
	d_and_h.height = ft_atoi_fractional(str[4]);
	get_colour(&(rgb), str[5], "Cylinder colour format: r,g,b.");
	if (!colour_op_validation(rgb))
		different_errors("You should put Cylinder rgb between 0<=r,g,b<=255");
	return (create_cylinder(a, orientation, d_and_h, rgb));
}
