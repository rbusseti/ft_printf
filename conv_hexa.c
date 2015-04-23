#include "ft_printf.h"

static char	*ft_get_str_size(unsigned int d, int *len)
{
    int		i;
    char	*hexa_nb;

    i = 0;
    while (d > 15)
    {
	d = d / 16;
	i++;
    }
    hexa_nb = malloc(sizeof(char) * (i + 2));
    hexa_nb[i + 1] = '\0';
    *len = i;
    return (hexa_nb);
}

static char	*ft_base_hexa(unsigned int d)
{
    int		i;
    int		len;
    int		mod;
    char	*hexa_nb;

    hexa_nb = ft_get_str_size(d, &len);
    i = 0;
    while (d > 15)
    {
	mod = d % 16;
	if (mod <= 9)
	    hexa_nb[len - i] = mod + '0';
	else
	    hexa_nb[len - i] = mod - 10 + 'a';
	d = d / 16;
	i++;
    }
    if (d <= 9)
	hexa_nb[len - i] = d + '0';
    else
	hexa_nb[len - i] = d - 10 + 'a';
    return (hexa_nb);
}

char	*ft_conv_hexa(va_list ap)
{
    unsigned int	d;
    char		*hexa_nb;

    d = va_arg(ap, unsigned int);
    hexa_nb = ft_base_hexa(d);
    return (hexa_nb);
}
