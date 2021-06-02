#ifndef INVESTIGATION_OF_DATA_H
# define INVESTIGATION_OF_DATA_H

int		number_of_words(char **str);
void	get_coordinates(t_vector *axis, char *str, char *message);
void	get_file(t_scene *scene, int fd);
int		ft_get_data(t_scene *scene, char *s);
void	create_scene(t_scene *scene);

#endif
