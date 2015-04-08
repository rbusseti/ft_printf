#include "libft.h"

int	ft_list_size(t_list **list)
{
    t_list	*temp;
    int		i;

    i = 0;
    temp = *list;
    while (temp)
    {
	i++;
	temp = temp->next;
    }
    return (i);
}
