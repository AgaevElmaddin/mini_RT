#include "../minirt.h"

t_square	*create_square(t_vector center, t_vector orientation, double side,
			t_colour_op	rgb)
{
	t_square	*square;

	square = malloc(sizeof(t_square));
	if (!square)
		different_errors("Can't allocate memory for Square");
	square->center = center;
	square->orientation = normalized_v(orientation);
	square->side = side;
	square->rgb = rgb;
	return (square);
}
