#include "ft_printf.h"

static void	ft_left_field(char *new, char *to_print, int size, int f_size)
{
    int		i;
    int		j;

    i = 0;
    j = 0;
    while (i < (f_size - size))
    {
        new[i] = ' ';
        i++;
    }
    while (i < f_size)
    {
        new[i] = to_print[j];
        i++;
	j++;
    }
    new[i] = '\0';
}

static void	ft_right_field(char *new, char *to_print, int f_size)
{
    int		i;

    i = 0;
    while (to_print[i])
    {
	new[i] = to_print[i];
	i++;
    }
    while (i < f_size)
    {
	new[i] = ' ';
	i++;
    }
    new[i] = '\0';
}

char		*ft_change_field_size(char *to_print, t_opt *options)
{
    int         size;
    char        *new;

    size = ft_strlen(to_print);
    if (options->fld_size < 0)
    {
	options->fld_size = options->fld_size * - 1;
	options->minus = 1;
    }
    if (to_print[0] == '\0' && (options->conv & C_UCHAR))
    {
	options->fld_size--;
	options->fld_m = 1;
    }
    if (options->fld_size <= size)
        return (to_print);
    new = malloc(sizeof(char) * (options->fld_size) + 1);
    if (options->minus == 0)
	ft_left_field(new, to_print, size, options->fld_size);
    else
	ft_right_field(new, to_print, options->fld_size);
    return (new);
}
