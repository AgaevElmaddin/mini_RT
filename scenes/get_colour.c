#include "../minirt.h"

void	get_colour(t_colour_op *rgb, char *str, char *message)
{
	char	**take_rgb;

	take_rgb = ft_split(str, ',');
	if (number_of_words(take_rgb) != 3)
		different_errors(message);
	rgb->red = ft_atoi(take_rgb[0]);
	rgb->green = ft_atoi(take_rgb[1]);
	rgb->blue = ft_atoi(take_rgb[2]);
	free_split(0, take_rgb);
}
