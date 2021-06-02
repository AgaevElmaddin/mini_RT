#include "../minirt.h"
#include <errno.h>
#include <stdio.h>

int	ft_get_data(t_scene *scene, char *s)
{
	char	**str;

	str = ft_split(s, ' ');
	if (ft_strncmp(str[0], "R", 1) == 0 && !scene->viewport)
		scene->viewport = get_resolution(str);
	else if (ft_strncmp(str[0], "A", 1) == 0 && !scene->ambient)
		scene->ambient = get_ambient(str);
	else if (ft_strncmp(str[0], "cy", 2) == 0)
		ft_lobject_add_back(CYLINDER, get_cylinder(str), &(scene->objs));
	else if (ft_strncmp(str[0], "c", 1) == 0)
		ft_lobject_add_back(CAMERA, get_camera(str), &(scene->cameras));
	else if (ft_strncmp(str[0], "l", 1) == 0)
		ft_lobject_add_back(LIGHT, get_light(str), &(scene->lights));
	else if (ft_strncmp(str[0], "sp", 2) == 0)
		ft_lobject_add_back(SPHERE, get_sphere(str), &(scene->objs));
	else if (ft_strncmp(str[0], "pl", 2) == 0)
		ft_lobject_add_back(PLANE, get_plane(str), &(scene->objs));
	else if (ft_strncmp(str[0], "sq", 2) == 0)
		ft_lobject_add_back(SQUARE, get_square(str), &(scene->objs));
	else if (strncmp(str[0], "tr", 2) == 0)
		ft_lobject_add_back(TRIANGLE, get_triangle(str), &(scene->objs));
	else if (ft_strncmp(str[0], "#", 1) == 0)
		return (free_split(1, str));
	return (free_split(0, str));
}

void	get_file(t_scene *scene, int fd)
{
	char		*line;

	while ((get_next_line(fd, &line)) > 0)
	{
		if (line && ft_strlen(line))
		{
			if (!ft_get_data(scene, line))
			{
				close(fd);
				different_errors("Something wrong with file. Try again!");
			}
		}
		if (!line)
			different_errors("Something wrong with file. Try again!");
		free(line);
	}
	ft_get_data(scene, line);
	free(line);
	create_scene(scene);
	close(fd);
}
