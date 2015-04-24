#include "ft_printf.h"

static int	ft_iscno(char *cmd)
{
    int		i;

    i = 1;
    while (cmd[i])
    {
	if (ft_isalpha(cmd[i]) && (i != (int)(ft_strlen(cmd) - 1)))
	    return (1);
	if (cmd[i] == '*' && ft_isdigit(cmd[i - 1]))
	    return (1);
	i++;
    }
    return (0);
}

static void     ft_convert(char *cmd, t_opt *options, int i)
{
    if (ft_iscno(cmd))
        options->conv |= C_NO;
    else if (cmd[i] == 'd' || cmd[i] == 'i')
        options->conv |= C_SDEC;
    else if (cmd[i] == 'u')
        options->conv |= C_UDEC;
    else if (cmd[i] == 'o')
        options->conv |= C_OCTA;
    else if (cmd[i] == 'x')
        options->conv |= C_HEXA;
    else if (cmd[i] == 'p')
        options->conv |= C_PTR;
    else if (cmd[i] == 'c')
        options->conv |= C_UCHAR;
    else if (cmd[i] == 's')
        options->conv |= C_STR;
    else if (cmd[i] == '%')
	options->d_mod = 1;
    else
        options->error = 1;
}


static int	ft_get_attr(char *cmd, int i, t_opt *options)
{
    if (cmd[i] == '+')
    {
	options->plus = 1;
	return (1);
    }
    else if (cmd[i] == '-')
    {
	options->minus = 1;
	return (1);
    }
    else if (cmd[i] == ' ')
    {
	options->space = 1;
	return (1);
    }
    else if (cmd[i] == '#')
    {
	options->hash = 1;
	return (1);
    }
    else if (cmd[i] == '0')
    {
	options->fzero = 1;
	return (1);
    }
    else
	return (0);
}

int		ft_parse_command(va_list ap, char *cmd)
{
    t_opt	*options;
    int		i;

    options = ft_init_struct();
    i = 1;
    ft_convert(cmd, options, ft_strlen(cmd) -1);
    if (options->conv & C_NO)
	return (ft_conv_no(cmd, ap));
    while (ft_get_attr(cmd, i, options))
	i++;
    ft_get_field(cmd, &i, options, ap);
    if (cmd[i] == '.' || ft_isdigit(cmd[i]))
    {
	options->isprec = 1;
	options->prec = ft_get_prec(cmd, &i, ap);
	if (options->prec < 0)
	    options->isprec = 0;
    }
    return (ft_print_command(ap, options));
}
