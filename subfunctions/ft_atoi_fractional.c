#include "../minirt.h"

double	ft_atoi_fractional(char *str)
{
	double	res;
	double	count_minus;
	int		i;
	int		j;

	count_minus = 1;
	res = 0;
	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			count_minus = -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (str[i++] == '.')
		j = i;
	while (str[i] >= '0' && str[i] <= '9' && j != 0)
		res = res * 10 + (str[i++] - '0');
	while (i-- > j && j != 0)
		res = res / 10;
	return (res * count_minus);
}
