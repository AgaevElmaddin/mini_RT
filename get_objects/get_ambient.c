#include "../minirt.h"

t_light	*get_ambient(char **str)
{
	char		*message;
	t_vector	light_point;
	double		brightness;
	t_colour_op	rgb;

	message = "According to the subject Ambient format:"
		"(light point),  (brightness),  (r,g,b)";
	if (number_of_words(str) != 3)
		different_errors(message);
	light_point = create_vector(0, 0, 0);
	brightness = ft_atoi_fractional(str[1]);
	get_colour(&(rgb), str[2], "Ambient colour format: r,g,b.");
	if (!colour_op_validation(rgb))
		different_errors("You should put Ambient rgb between 0<=r,g,b<=255");
	if (brightness < 0 || brightness > 1)
		different_errors("You should put Ambient brightness between [0 ; 1]");
	return (create_light(light_point, brightness, rgb));
}
