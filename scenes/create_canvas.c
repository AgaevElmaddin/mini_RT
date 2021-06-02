#include "../minirt.h"

t_canvas	*create_canvas(int width, int height, int d)
{
	t_canvas	*canvas;

	canvas = malloc(sizeof(t_canvas));
	if (!canvas)
		different_errors("Can't allocate memory for Canvas.");
	canvas->width = width;
	canvas->height = height;
	canvas->d = d;
	return (canvas);
}
