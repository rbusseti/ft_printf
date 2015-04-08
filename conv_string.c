#include "ft_printf.h"

char	*ft_conv_str(va_list ap)
{
    char	*str;

    if ((str = va_arg(ap, char *)) == NULL)
	return ("(null)");
    else
	return (str);
	
}
