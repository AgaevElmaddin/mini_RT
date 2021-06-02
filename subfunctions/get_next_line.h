#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl
{
	char		*buff;
	int			read_letter;
	char		*tmp;
}				t_gnl;

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_new_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_mod_strchr(const char *s, int c);
char	*ft_several_n(char **str_after_n, char **line);
int		free_str_after_n(char *str_after_n);
void	fill_line(char **line, char *buff);
void	fill_line_second(char **line, char *buff);

#endif
