#include "ft_printf.h"

int	ft_find_plus(char *cmd, int i)
{
    while (cmd[i])
    {
	if (cmd[i] == '+')
	    return (1);
	i++;
    }
    return (0);
}

int	ft_aff_space(int ret, char *cmd, int *ind)
{
    int		i;

    i = *ind;
    if (ft_find_plus(cmd, i))
	return (ret - 1);
    if (cmd[i + 1] == '+')
    {
	ft_putchar('+');
	*ind = i + 1;
	return (ret - 1);
    }
    else if (cmd[i + 1] == '#')
    {
	ft_putchar('#');
	ft_putchar(' ');
	*ind = i + 1;
    }
    else
	ft_putchar(' ');
    return (ret);
}

int	ft_aff_plus(int ret, char *cmd, int *ind)
{
    int		i;

    i = *ind;
    if (cmd[i + 1] == '+')
    {
	ft_putchar('+');
	ft_putchar('-');
	*ind = i + 1;
    }
    else
	ft_putchar('-');
    return (ret);
}
