#include "../minirt.h"

t_plane	*create_plane(t_vector p0, t_vector orientation, t_colour_op rgb)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		different_errors("Can't allocate memory for Plane");
	plane->p0 = p0;
	plane->orientation = normalized_v(orientation);
	plane->rgb = rgb;
	return (plane);
}
