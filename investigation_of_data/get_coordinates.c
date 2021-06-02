#include "../minirt.h"

void	get_coordinates(t_vector *axis, char *str, char *message)
{
	char	**tmp;

	tmp = ft_split(str, ',');
	if (number_of_words(tmp) != 3)
		different_errors(message);
	axis->x = ft_atoi_fractional(tmp[0]);
	axis->y = ft_atoi_fractional(tmp[1]);
	axis->z = ft_atoi_fractional(tmp[2]);
	free_split(0, tmp);
}
