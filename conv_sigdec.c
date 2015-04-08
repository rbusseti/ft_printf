#include "ft_printf.h"

char	*ft_conv_sigdec(va_list ap)
{
    int		d;

    if ((d = va_arg(ap, int)) == -2147483648)
	return ("-2147483648");
    else
	return (ft_itoa(d));
}
