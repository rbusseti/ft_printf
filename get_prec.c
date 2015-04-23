#include "ft_printf.h"

static char	*ft_get_size(char *cmd, int *ind)
{
    int		i;
    int		j;
    char	*new;

    j = *ind;
    i = 0;
    while (ft_isdigit(cmd[j]))
	j++;
    new = malloc(sizeof(char) * (j + 1));
    j = *ind;
    while (ft_isdigit(cmd[j]))
    {
	new[i] = cmd[j];
	i++;
	j++;
    }
    new[i] = '\0';
    *ind = j;
    return (new);
}

int		ft_get_prec(char *cmd, int *index, va_list ap)
{
    int		i;
    char	*new;

    if (cmd[*index] == '.')
	i = *index + 1;
    else
	i = *index;
    if (cmd[i] == '*')
    {
	*index = i + 1;
	return (va_arg(ap, int));
    }
    if (!(ft_isdigit(cmd[i])))
    {
	*index = i;
	return (0);
    }
    new = ft_get_size(cmd, &i);
    *index = i;
    return (ft_atoi(new));
}
