#include "ft_printf.h"

static int	ft_get_field_size(char *cmd, int *index)
{
    int         i;
    int         j;
    char        *size;

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
    *index = i;
    return (ft_atoi(size));
}

void		ft_get_field(char *cmd, int *ind, t_opt *options, va_list ap)
{
    int         i;

    i = *ind;
    if (cmd[i] == '*')
    {
        options->fld_size = va_arg(ap, int);
        i++;
    }
    else if (ft_isdigit(cmd[i]))
            options->fld_size = ft_get_field_size(cmd, &i);
    *ind = i;
}
