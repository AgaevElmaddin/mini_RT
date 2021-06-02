#include "../minirt.h"

t_light	*create_light(t_vector light_point, double brightness, t_colour_op rgb)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		different_errors("Can't allocate memory for light");
	light->light_point = light_point;
	light->brightness = brightness;
	light->rgb = rgb;
	return (light);
}
