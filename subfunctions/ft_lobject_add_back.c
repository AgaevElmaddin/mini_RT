#include "../minirt.h"

void	ft_lobject_add_back(int type, void *obj, t_lobject **lst)
{
	t_lobject	*start;

	if (!obj)
		return ;
	start = *lst;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = ft_lobject_new(type, obj);
	}
	else
		*lst = ft_lobject_new(type, obj);
}
