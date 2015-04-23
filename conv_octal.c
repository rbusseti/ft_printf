#include "ft_printf.h"

static char	*ft_get_str_size(unsigned int d, int *len)
{
    int		i;
    char	*octal_nb;

    i = 0;
    while (d > 7)
    {
	d = d / 8;
	i++;
    }
    octal_nb = malloc(sizeof(char) * (i + 2));
    octal_nb[i + 1] = '\0';
    *len = i;
    return (octal_nb);
}

static char	*ft_base_octal(unsigned int d)
{
    int		i;
    int		len;
    int		mod;
    char	*octal_nb;

    octal_nb = ft_get_str_size(d, &len);
    i = 0;
    while (d > 7)
    {
	mod = d % 8;
	octal_nb[len - i] = mod + '0';
	d = d / 8;
	i++;
    }
    octal_nb[len - i] = d + '0';
    return (octal_nb);
}

char		*ft_conv_octal(va_list ap)
{
    unsigned int    d;
    char	    *octal_nb;

    d = va_arg(ap, unsigned int);
    octal_nb = ft_base_octal(d);
    return (octal_nb);
}
