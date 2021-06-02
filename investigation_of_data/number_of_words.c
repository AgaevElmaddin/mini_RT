#include "../minirt.h"

int	number_of_words(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
