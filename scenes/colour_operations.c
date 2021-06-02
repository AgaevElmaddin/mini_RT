#include "../minirt.h"

int	f_min_max(int n, int min, int max)
{
	if (n < min)
		n = min;
	if (n > max)
		n = max;
	return (n);
}

t_colour_op	colour_addition(t_colour_op rgb1, t_colour_op rgb2)
{
	t_colour_op	result;

	result.red = fmin(rgb1.red + rgb2.red, 255);
	result.green = fmin(rgb1.green + rgb2.green, 255);
	result.blue = fmin(rgb1.blue + rgb2.blue, 255);
	return (result);
}

t_colour_op	ambient_light(t_colour_op rgb, t_light *light)
{
	t_colour_op	res;
	double		part_r;
	double		part_g;
	double		part_b;

	part_r = 0;
	part_g = 0;
	part_b = 0;
	if (light)
	{
		part_r = ((double)light->rgb.red * light->brightness) / 255;
		part_g = ((double)light->rgb.green * light->brightness) / 255;
		part_b = ((double)light->rgb.blue * light->brightness) / 255;
	}
	res.red = rgb.red * part_r;
	res.green = rgb.green * part_g;
	res.blue = rgb.blue * part_b;
	return (res);
}

t_colour_op	diffuse_light(t_colour_op rgb, t_light *light, double dot_angle)
{
	t_colour_op	res;
	double		part_r;
	double		part_g;
	double		part_b;
	double		check_dot_angle;

	check_dot_angle = dot_angle;
	if (check_dot_angle < 0)
		check_dot_angle = 0;
	part_r = ((double)light->rgb.red * light->brightness) / 255;
	part_g = ((double)light->rgb.green * light->brightness) / 255;
	part_b = ((double)light->rgb.blue * light->brightness) / 255;
	res.red = rgb.red * part_r * check_dot_angle;
	res.green = rgb.green * part_g * check_dot_angle;
	res.blue = rgb.blue * part_b * check_dot_angle;
	return (res);
}

int	create_trgb(t_colour_op rgb)
{
	return (rgb.red << 16 | rgb.green << 8 | rgb.blue);
}
