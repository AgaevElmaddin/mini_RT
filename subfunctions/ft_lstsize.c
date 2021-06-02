#include "../minirt.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*start;
	int		i;

	start = lst;
	i = 0;
	while (start != NULL)
	{
		i++;
		start = start->next;
	}
	return (i);
}
