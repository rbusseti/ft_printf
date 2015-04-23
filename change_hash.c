#include "ft_printf.h"

char	*ft_change_hash(char *to_print, t_opt *options)
{
    if ((options->conv & C_OCTA) && to_print[0] != '0')
	to_print = ft_strjoin("0", to_print);
    if (options->conv & C_HEXA)
    {
	if (to_print[0] != '0')
	    to_print = ft_strjoin("0x", to_print);
    }
    return (to_print);
}
