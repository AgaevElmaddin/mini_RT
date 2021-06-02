#include "../minirt.h"

t_triangle	*create_triangle(t_vector first_point, t_vector second_point,
							t_vector third_point, t_colour_op rgb)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	if (!triangle)
		different_errors("Can't allocate memory for Triangle");
	triangle->first_point = first_point;
	triangle->second_point = second_point;
	triangle->third_point = third_point;
	triangle->rgb = rgb;
	return (triangle);
}
