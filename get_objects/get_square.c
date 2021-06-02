#include "../minirt.h"

t_square	*get_square(char **str)
{
	char		*message;
	t_vector	center;
	t_vector	orientation;
	double		side;
	t_colour_op	rgb;

	message = "According to the subject Square format:"
		"(sq)  (center)  (normal)  (side)  (r,g,b)";
	if (number_of_words(str) != 5)
		different_errors(message);
	get_coordinates(&(center), str[1], message);
	get_coordinates(&(orientation), str[2], message);
	normalized_v(orientation);
	side = ft_atoi_fractional(str[3]);
	get_colour(&(rgb), str[4], "Square colour format: r,g,b.");
	if (!colour_op_validation(rgb))
		different_errors("You should put Square rgb between 0<=r,g,b<=255");
	return (create_square(center, orientation, side, rgb));
}
