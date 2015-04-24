#include "ft_printf.h"

static char  *ft_print_conv(va_list ap, t_opt *options)
{
    char	*to_print;

    if(options->conv & C_SDEC)
	to_print = ft_conv_sigdec(ap);
    else if(options->conv & C_UDEC)
	to_print = ft_conv_unsigdec(ap);
    else if(options->conv & C_OCTA)
	to_print = ft_conv_octal(ap);
    else if(options->conv & C_HEXA)
	to_print = ft_conv_hexa(ap);
    else if(options->conv & C_PTR)
	to_print = ft_conv_ptr(ap);
    else if(options->conv & C_UCHAR)
    {
	to_print = ft_conv_unsigchar(ap);
	if (to_print[0] == '\0')
	    options->p_zero = 1;
    }
    else if(options->conv & C_STR)
	to_print = ft_conv_str(ap);
    else
	return (NULL);
    return (to_print);
}

static int  ft_isspace(t_opt *options, char *to_print)
{
    if (options->space == 1)
    {
	if (options->conv & C_STR)
	    return (0);
	else if (options->conv & C_UCHAR)
	    return (0);
	else if (options->conv & C_UDEC)
	    return (0);
	else if (options->conv & C_OCTA)
	    return (0);
	else if (options->conv & C_HEXA)
	    return (0);
	else if ((options->conv & C_PTR) && (ft_strcmp(to_print, "(nil)") == 0))
	    return (0);
	else if (to_print[0] == '-')
	    return (0);
	else
	    return (1);
    }
    else
	return (0);
}

static int  ft_make_print(char *to_print, t_opt *options)
{
    if (options->minus == 1)
    {
	if (options->p_zero == 1)
	{
	    write(1, "\0", 1);
	    ft_putstr(to_print);
	    if (to_print[0] == '\0' || options->fld_m == 1)
		return (ft_strlen(to_print) + 1);
	}
	else
	    ft_putstr(to_print);
    }
    else
    {
	ft_putstr(to_print);
	if (options->p_zero == 1)
	{
	    write(1, "\0", 1);
	    if (to_print[0] == '\0' || options->fld_m == 1)
		return (ft_strlen(to_print) + 1);
	}

    }
    return (ft_strlen(to_print));
}

static void     ft_update_fzero(t_opt *options, char *to_print)
{
    if (options->minus == 1)
        options->fzero = 0;
    else if (options->fld_size != 0 && (options->conv & C_SDEC || \
	     options->conv & C_UDEC || options->conv & C_OCTA || \
	     options->conv & C_HEXA || \
	     (options->conv & C_PTR && ft_strcmp(to_print, "(nil)") != 0)))
    {
        if (options->isprec == 1)
            options->fzero = 0;
        else if (options->fld_size != 0)
        {
            options->isprec = 1;
	    if (options->conv & C_PTR)
		options->prec = options->fld_size - 2;
	    else
		options->prec = options->fld_size;
            options->fld_size = 0;
        }
    }
}


int	    ft_print_command(va_list ap, t_opt *options)
{
    char	*to_print;

    if (options->d_mod == 1)
    {
	ft_putchar('%');
	return (1);
    }
    if (options->error == 1)
	return (-1);
    to_print = ft_print_conv(ap, options);
    if (options->fzero)
	ft_update_fzero(options, to_print);
    if (options->hash == 1)
	to_print = ft_change_hash(to_print, options);
    if (options->plus == 1)
	to_print = ft_change_plus(to_print, options);
    if (ft_isspace(options, to_print))
	to_print = ft_strjoin(" ", to_print);
    if (options->isprec == 1 && !(options->conv & C_UCHAR))
	to_print = ft_change_precision(to_print, options);
    if (options->fld_size != 0)
	to_print = ft_change_field_size(to_print, options);
    return (ft_make_print(to_print, options));
}
