#include "ft_printf.h"

int		ft_get_args(va_list ap, char **split_format)
{
    int		i;
    int		len;
    int		len_varg;

    i = 0;
    len = 0;
    len_varg = 0;
    while (split_format[i])
    {
	if (split_format[i][0] == '%')
	{
	    len_varg = ft_parse_command(ap, split_format[i]);
	    if (len_varg != -1)
		len = len + len_varg;
	    else
		return (-1);
	}
	else
	{
	    ft_putstr(split_format[i]);
	    len = len + ft_strlen(split_format[i]);
	}
	i++;
    }
    return (len);
}
