#include "../minirt.h"

int	free_split(int flag, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	if (flag)
		return (0);
	return (1);
}
