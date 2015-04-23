#include "ft_printf.h"

char	*ft_conv_sigdec(va_list ap)
{
    int		d;
    char	*to_ret;

    if ((d = va_arg(ap, int)) == -2147483648)
	return ("-2147483648");
    else
	to_ret = ft_itoa(d);
    return (to_ret);
}
