#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
    va_list	ap;
    int		len;
    char	**split_args;

    split_args = ft_split_args(format);
    va_start(ap, format);
    len = ft_get_args(ap, split_args);
    va_end(ap);
    return (len);
}
