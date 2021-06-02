#include "../minirt.h"

void	different_errors(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(-1);
}

void	input_validation(int argc, char **argv, int *fd)
{
	int	i;

	i = 0;
	if (argc < 2 || argc > 3 || (argc == 3
			&& ft_strncmp(argv[2], "--save", 6) != 0))
		different_errors("wrong input");
	while (argv[1][i])
		i++;
	if (i < 4)
		different_errors("wrong input");
	if (argv[1][i - 1] != 't' || argv[1][i - 2] != 'r' || argv[1][i - 3] != '.')
		different_errors("wrong input");
	*fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		different_errors("invalid file");
}
