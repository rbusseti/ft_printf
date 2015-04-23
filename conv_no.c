#include "ft_printf.h"

static int	ft_aff_star(va_list ap, int ret, char *cmd, int *ind)
{
    char	*str;
    int		nb;
    int		i;

    nb = 0;
    i = *ind;
    if (ft_isdigit(cmd[i - 1]))
    {
	ft_putchar('*');
	ret++;
    }
    else if ((nb = va_arg(ap, int)) != 0)
    {
	ft_putstr(str = ft_itoa(nb));
	ret = ret + ft_strlen(str);
    }
    else if (cmd[i - 1] == '.')
    {
	ft_putchar('*');
	*ind = *ind + 1;
    }
    ret--;
    return (ret);
}

static int	ft_point_star(int *ind, va_list ap, int ret, char *s)
{
    char	*str;
    int		nb;
    int		i;

    i = *ind + 2;
    nb = 0;
    if ((nb = va_arg(ap, int)) >= 0)
    {
	ft_putchar('.');
	if ((ft_isalpha(s[i]) || s[i] == '%') && (s[i - 3] == '*' && i - 3 != 1))
	    ft_putchar('*');
	else
	{
	    ft_putstr(str = ft_itoa(nb));
	    ret = ret + ft_strlen(str) - 1;
	}
    }
    else if ((ft_isalpha(s[i]) || s[i] == '%')&& (s[i - 3] == '*' && i - 3 != 1))
	ft_putstr(".*");
    else
	ret = ret - 2;
    *ind = *ind + 1;
    return (ret);
}

static int	ft_aff_point(va_list ap, int ret, char *cmd, int *ind)
{
    int		i;

    i = *ind;
    if (cmd[i] == '.' && cmd[i + 1] == '*')
	ret = ft_point_star(&i, ap, ret, cmd);
    else if (cmd[i] == '.' && !(ft_isdigit(cmd[i + 1])) \
	     && cmd[i + 1] != '*' && !(ft_isdigit(cmd[i - 2])) && \
	     (cmd[i - 1] != '*' || ft_isalpha(cmd[i + 1])))
    {
	ft_putstr(".0");
	ret = ret + 1;
    }
    else
	ft_putchar('.');
    *ind = i;
    return (ret);
}

int		ft_conv_no(char *cmd, va_list ap)
{
    int		i;
    int		ret;

    i = 0;
    ret = 0;
    while (cmd[i] != '\0')
    {
	if (cmd[i] == '*')
	    ret = ft_aff_star(ap, ret, cmd, &i);
	else if (cmd[i] == '.')
	    ret = ft_aff_point(ap, ret, cmd, &i);
	else if (cmd[i] == ' ')
	    ret = ft_aff_space(ret, cmd, &i);
	else if (cmd[i] == '-')
	    ret = ft_aff_plus(ret, cmd, &i);
	else
	{
	    if (i > 1 && cmd[i] == '0' && cmd[i - 1] == '+' && cmd[i - 2] == '-')
		ret = ret - 1;
	    else
		ft_putchar(cmd[i]);
	}
	i++;
    }
    ret = i + ret;
    return (ret);
}
