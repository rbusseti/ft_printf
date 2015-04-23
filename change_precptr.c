#include "ft_printf.h"

static char	*ft_change_ptrplus(char *zero, int prec, int size)
{
    int		i;

    zero[0] = '+';
    zero[1] = '0';
    zero[2] = 'x';
    i = 3;
    while (i < prec - size + 5)
    {
        zero[i] = '0';
        i++;
    }
    zero[i] = '\0';
    return (zero);
}

static char	*ft_change_ptr(char *zero, int prec, int size)
{
    int		i;

    zero[0] = '0';
    zero[1] = 'x';
    i = 2;
    while (i < prec - size + 4)
    {
        zero[i] = '0';
        i++;
    }
    zero[i] = '\0';
    return (zero);
}

char     *ft_change_precptr(char *to_print, int prec, int size)
{
    char        *zero;

    if ((prec != 0) && (size >= prec + 2))
        return (to_print);
    if (ft_strcmp(to_print, "(nil)") == 0)
        return (to_print);
    if (prec == 0)
	return (to_print);
    zero = malloc(sizeof(char) * (prec - size + 4));
    if (to_print[0] != '+')
	return (ft_strjoin(ft_change_ptr(zero, prec, size), to_print + 2));
    else
	return (ft_strjoin(ft_change_ptrplus(zero, prec, size), to_print + 3));
}
