#include "ft_printf.h"

static char	*ft_change_number(char *to_print, int prec, int size)
{
    int		i;
    char	*zero;

    if (prec == 0 && to_print[0] == '0')
	return ("");
    else if (prec == 0 && to_print[0] != '0')
	return (to_print);
    i = 0;
    zero = malloc(sizeof(char) * (prec - size + 2));
    if (to_print[0] == '+')
    {
	to_print = to_print + 1;
	zero[0] = '+';
	i++;
	prec++;
    }
    while (i < (prec - size))
    {
	zero[i] = '0';
	i++;
    }
    zero[i] = '\0';
    return (ft_strjoin(zero, to_print));
}

static char	*ft_change_negnumber(char *to_print, int prec, int size)
{
    int		i;
    char	*zero;

    if (prec == 0 && to_print[1] == '0')
	return ("");
    else if (prec == 0 && to_print[1] != '0')
	return (to_print);
    i = 1;
    zero = malloc(sizeof(char) * (prec - size + 3));
    zero[0] = '-';
    while (i < (prec - size + 2))
    {
	zero[i] = '0';
	i++;
    }
    zero[i] = '\0';
    return (ft_strjoin(zero, to_print + 1));
}

static char	*ft_change_str(char *to_print, int prec, int size)
{
    if (ft_strcmp(to_print, "(null)") == 0)
    {
	if (prec >= 6)
	    return ("(null)");
	else
	    return ("");
    }
    if (prec >= size)
	return (to_print);
    to_print = ft_strsub(to_print, 0, prec);
    return (to_print);
}

char	*ft_change_precision(char *to_print, t_opt *options)
{
    int		size;

    size = ft_strlen(to_print);
    if (options->conv & C_STR)
	return (ft_change_str(to_print, options->prec, size));
    else if (options->conv & C_PTR)
	return (ft_change_precptr(to_print, options->prec, size));
    else if ((options->prec != 0) && (size >= options->prec))
	return (to_print);
    else if (to_print[0] == '-' && options->fzero == 1)
	return (ft_change_negnumber(to_print, options->prec - 1, size));
    else if (to_print[0] == '-')
	return (ft_change_negnumber(to_print, options->prec, size));
    else
	return (ft_change_number(to_print, options->prec, size));
}
