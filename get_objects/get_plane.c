#include "../minirt.h"

t_plane	*get_plane(char **str)
{
	char		*message;
	t_vector	p0;
	t_vector	orientation;
	t_colour_op	rgb;

	message = "According to the subject Plane format:"
		"(pl),  (x,y,z coordinates),  (normal),  (rgb)";
	if (number_of_words(str) != 4)
		different_errors(message);
	get_coordinates(&(p0), str[1], message);
	get_coordinates(&(orientation), str[2], message);
	normalized_v(orientation);
	get_colour(&(rgb), str[3], "Plane colour format: r,g,b.");
	if (!colour_op_validation(rgb))
		different_errors("You should put Plane rgb between 0<=r,g,b<=255");
	return (create_plane(p0, orientation, rgb));
}
