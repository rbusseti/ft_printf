#include "ft_printf.h"

static void	ft_convert(char *cmd, t_opt *options, int i)
{
    if (ft_isalpha(cmd[i + 1]))
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
    else
	options->error = 1;
}

static int	ft_get_field_size(char *cmd, int *index)
{
    int		i;
    int		j;
    char	*size;

    i = *index;
    j = 0;
    while (ft_isdigit(cmd[i]))
    {
	i++;
	j++;
    }
    size = malloc(sizeof(char) * (j + 1));
    i = *index;
    j = 0;
    while (ft_isdigit(cmd[i]))
    {
	size[j] = cmd[i];
	i++;
	j++;
    }
    size[j] = '\0';
    *index = i - 1;
    return (ft_atoi(size));
}

static int	ft_get_speconv(char *cmd, int *ind, t_opt *options, va_list ap)
{
    int		i;

    i = *ind;
    if (cmd[i] == '#')
	options->hash = 1;
    else if (cmd[i] == '-')
	options->minus = 1;
    else if (cmd[i] == '+')
	options->plus = 1;
    else if (cmd[i] == '*')
	options->fld_size = va_arg(ap, unsigned int);
    else if (cmd[i] == '.')
    {
	options->prec = ft_get_prec(cmd, &i, ap);
	options->isprec = 1;
    }
    else if (ft_isdigit(cmd[i]))
	options->fld_size = ft_get_field_size(cmd, &i);
    else if (cmd[i] == ' ')
	options->space = 1;
    *ind = i + 1;
    return (1);
}

int		ft_parse_command(va_list ap, char *cmd)
{
    t_opt	*options;
    int		i;

    options = ft_init_struct();
    i = 1;
    while ((ft_isalpha(cmd[i]) != 1) && (cmd[i] != '\0'))
	ft_get_speconv(cmd, &i, options, ap);
    ft_convert(cmd, options, i);
    if (cmd[1] == '%')
	options->d_mod = 1;
    if (options->conv & C_NO)
    {
	ft_putstr(cmd);
	return (ft_strlen(cmd));
    }
    return (ft_print_command(ap, options));
}
