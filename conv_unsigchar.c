#include "ft_printf.h"

char	*ft_conv_unsigchar(va_list ap)
{
    char	*sc;

    sc = malloc(sizeof(char) * 2);
    sc[0] = va_arg(ap, int);
    sc[1] = '\0';
    return (sc);
}
