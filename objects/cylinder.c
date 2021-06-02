#include "../minirt.h"

t_cylinder	*create_cylinder(t_vector a, t_vector orientation,
							t_d_and_h d_and_h, t_colour_op rgb)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		different_errors("Can't allocate memory for Cylinder");
	cylinder->a = a;
	cylinder->orientation = normalized_v(orientation);
	cylinder->diameter = d_and_h.diameter;
	cylinder->height = d_and_h.height;
	cylinder->rgb = rgb;
	return (cylinder);
}
