#include "../minirt.h"

t_camera	*get_camera(char **str)
{
	char		*message;
	t_vector	origin;
	t_vector	direction;
	double		fov;

	message = "According to the subject Camera format:"
		"(c)  (origin x,y,z)  (normal x y z)  (fov)";
	if (number_of_words(str) != 4)
		different_errors(message);
	get_coordinates(&(origin), str[1], message);
	get_coordinates(&(direction), str[2], message);
	normalized_v(direction);
	fov = ft_atoi(str[3]);
	if (fov < 0 || fov > 180)
		different_errors("Camera fov should be in range 0 <= fov <= 180");
	return (create_camera(origin, direction, fov));
}
