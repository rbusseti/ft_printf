#include "ft_printf.h"

static char     *ft_get_str_size(unsigned long d, int *len)
{
    int         i;
    char        *hexa;

    i = 0;
    while (d > 15)
    {
	d = d / 16;
	i++;
    }
    hexa = malloc(sizeof(char) * (i + 4));
    hexa[i + 3] = '\0';
    *len = i + 2;
    return (hexa);
}

static char     *ft_base_hexa(unsigned long d)
{
    int         i;
    int         len;
    int         mod;
    char        *hexa_nb;

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
    hexa_nb[len - i - 1] = 'x';
    hexa_nb[len - i - 2] = '0';
    return (hexa_nb);
}

char	*ft_conv_ptr(va_list ap, t_opt *options)
{
    unsigned long	adr;
    char		*hexa_nb;

    adr = (unsigned long)va_arg(ap, unsigned long);
    hexa_nb = ft_base_hexa(adr);
    if (adr == 0)
	return ("(nil)");
    else
    {
	if (options->fld_size != 0 && options->isprec == 0 && \
	    options->zero_f == 1)
	{
	    options->isprec = 1;
	    options->prec = options->fld_size - 2;
	    options->fld_size = 0;
	}
	return (hexa_nb);
    }
}
