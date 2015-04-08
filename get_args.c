#include "ft_printf.h"

static int	ft_get_varg(va_list ap, char *str)
{
    char	*to_print;

    if (str[1] == 'd' || str[1] == 'i')
	to_print = ft_conv_sigdec(ap);
    else if (str[1] == 'u')
	to_print = ft_conv_unsigdec(ap);
    else if (str[1] == 'o')
	to_print = ft_conv_octal(ap);
    else if (str[1] == 'c')
    {
	to_print = ft_conv_unsigchar(ap);
	if (to_print[0] == '\0')
	{
	    write(1, "\0", 1);
	    return (1);
	}
    }
    else if (str[1] == 's')
	to_print = ft_conv_str(ap);
    ft_putstr(to_print);
    return (ft_strlen(to_print));
}

int		ft_get_args(va_list ap, char **split_format)
{
    int		i;
    int		len;

    i = 0;
    len = 0;
    while (split_format[i])
    {
	if (split_format[i][0] == '%')
	    len = len + ft_get_varg(ap, split_format[i]);
	else
	{
	    ft_putstr(split_format[i]);
	    len = len + ft_strlen(split_format[i]);
	}
	i++;
	if (split_format[i])
	{
	    ft_putchar(' ');
	    len++;
	}
    }
    return (len);
}
