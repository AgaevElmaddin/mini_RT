#include "../minirt.h"

t_light	*get_light(char **str)
{
	char		*message;
	t_vector	light_point;
	double		brightness;
	t_colour_op	rgb;

	message = "According to the subject Light format:"
		"(light point),  (brightness),  (r,g,b)";
	if (number_of_words(str) != 4)
		different_errors(message);
	get_coordinates(&(light_point), str[1], message);
	brightness = ft_atoi_fractional(str[2]);
	get_colour(&(rgb), str[3], "Light colour format: r,g,b.");
	if (!colour_op_validation(rgb))
		different_errors("You should put Light rgb between 0<=r,g,b<=255");
	if (brightness < 0 || brightness > 1)
		different_errors("You should put Light brightness between [0 ; 1]");
	return (create_light(light_point, brightness, rgb));
}
