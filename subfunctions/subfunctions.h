#ifndef SUBFUNCTIONS_H
# define SUBFUNCTIONS_H

typedef struct s_split
{
	int	i;
	int	j;
	int	k;
}				t_split;

double			ft_atoi_fractional(char *str);
int				ft_atoi(const char *str);
void			ft_lobject_add_back(int type, void *obj, t_lobject **lst);
t_lobject		*ft_lobject_new(int type, void *obj);
int				ft_lstsize(t_list *lst);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				free_split(int flag, char **str);

#endif
