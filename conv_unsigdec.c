#include "ft_printf.h"

static char	*ft_calc_unsigitoa(unsigned int n, int i, char *strnew)
{
    int		mod;

    while (n > 9)
    {
	i--;
	mod = n % 10;
	n = n / 10;
	strnew[i] = mod + '0';
    }
    strnew[i - 1] = n + '0';
    return (strnew);
}

static char	*ft_unsigitoa(int n)
{
    char		*strnew;
    int			i;
    unsigned int	un;
    unsigned int        nsave;

    i = 1;
    if (n < 0)
	un = 4294967295 + n + 1;
    else
	un = n;
    nsave = un;
    while (un > 9)
    {
	un = un / 10;
	i++;
    }
    if ((strnew = malloc(sizeof(char) * (i + 1))) == NULL)
	return (NULL);
    strnew[i] = '\0';
    strnew = ft_calc_unsigitoa(nsave, i, strnew);
    return (strnew);
}

char		*ft_conv_unsigdec(va_list ap)
{
    int		ud;

    ud = va_arg(ap, int);
    return (ft_unsigitoa(ud));
}
