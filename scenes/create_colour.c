#include "../minirt.h"

t_colour_op	create_colour(int red, int green, int blue)
{
	t_colour_op	rgb;

	rgb.red = red;
	rgb.green = green;
	rgb.blue = blue;
	return (rgb);
}
