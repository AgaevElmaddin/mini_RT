#include "../minirt.h"

t_sphere	*get_sphere(char **str)
{
	char		*message;
	t_vector	center;
	double		diameter;
	t_colour_op	rgb;

	message = "According to the subject Sphere format:"
		"(sp)  (center)  (diameter)  (r,g,b)";
	if (number_of_words(str) != 4)
		different_errors(message);
	get_coordinates(&(center), str[1], message);
	diameter = ft_atoi_fractional(str[2]);
	get_colour(&(rgb), str[3], "Sphere colour format: r,g,b.");
	if (!colour_op_validation(rgb))
		different_errors("You should put Sphere rgb between 0<=r,g,b<=255");
	return (create_sphere(center, diameter, rgb));
}
