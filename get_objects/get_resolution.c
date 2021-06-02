#include "../minirt.h"

t_canvas	*get_resolution(char **str)
{
	int	width;
	int	height;

	if (number_of_words(str) != 3)
		different_errors("According to the subject Resolution format:"
			"(R),  (weight),  (height)");
	width = ft_atoi(str[1]);
	height = ft_atoi(str[2]);
	if (width < 1 || height < 1)
		different_errors("Something wrong with Resolution. Try again!");
	return (create_canvas(width, height, 1));
}
