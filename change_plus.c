#include "ft_printf.h"

char	*ft_change_plus(char *to_print, t_opt *options)
{
    options->space = 0;
    if (options->conv & C_SDEC)
    {
	if (to_print[0] != '-' && to_print[0] != '+')
	    to_print = ft_strjoin("+", to_print);
    }
    else if (options->conv & C_PTR)
    {
	if (ft_strcmp(to_print, "(nil)") != 0)
	    to_print = ft_strjoin("+", to_print);
    }
    return (to_print);
}
