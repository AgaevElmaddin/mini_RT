#include "../minirt.h"

t_triangle	*get_triangle(char **str)
{
	char		*message;
	t_vector	first_point;
	t_vector	second_point;
	t_vector	third_point;
	t_colour_op	rgb;

	message = "According to the subject Triangle format:"
		"(tr),  (first point),  (second point),  (third_point)  (rgb)";
	if (number_of_words(str) != 5)
		different_errors(message);
	get_coordinates(&(first_point), str[1], message);
	get_coordinates(&(second_point), str[2], message);
	get_coordinates(&(third_point), str[3], message);
	get_colour(&(rgb), str[4], "Triangle colour format: r,g,b.");
	if (!colour_op_validation(rgb))
		different_errors("You should put Triangle rgb between 0<=r,g,b<=255");
	return (create_triangle(first_point, second_point, third_point, rgb));
}
