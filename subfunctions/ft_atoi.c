#include "../minirt.h"

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				i;
	int				count_minus;

	count_minus = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			count_minus = -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (res > 9223372036854775807)
	{
		if (count_minus == 1)
			return (0);
		return (-1);
	}
	return (res * count_minus);
}
