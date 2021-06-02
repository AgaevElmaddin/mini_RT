#include "../minirt.h"

t_sphere	*create_sphere(t_vector center, double diameter, t_colour_op rgb)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		different_errors("Can't allocate memory for Sphere");
	sphere->center = center;
	sphere->diameter = diameter;
	sphere->rgb = rgb;
	return (sphere);
}
