#include "../minirt.h"

int	colour_op_validation(t_colour_op rgb)
{
	if (rgb.red < 0 || rgb.red > 255 || rgb.green < 0 ||rgb.green > 255
		|| rgb.blue < 0 || rgb.blue > 255)
		return (0);
	return (1);
}
