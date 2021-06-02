#include "../minirt.h"

t_lobject	*ft_lobject_new(int type, void *obj)
{
	t_lobject	*new_el;

	new_el = (t_lobject *)malloc(sizeof(t_lobject));
	if (!new_el)
		return (NULL);
	new_el->type = type;
	new_el->obj = obj;
	new_el->next = NULL;
	return (new_el);
}
