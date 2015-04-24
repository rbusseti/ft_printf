#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>

# include "libft.h"

/*
** CONVERSION FLAGS
*/

# define C_SDEC 0b00000001
# define C_STR 0b00000010
# define C_UCHAR 0b00000100
# define C_UDEC 0b00001000
# define C_OCTA 0b00010000
# define C_HEXA 0b00100000
# define C_PTR 0b01000000
# define C_NO 0b10000000

typedef struct	s_opt
{
    char       	conv;
    char	space;
    char	error;
    char	d_mod;
    char	p_zero;
    char	hash;
    char	plus;
    char	minus;
    char	isprec;
    char	fld_m;
    char	zero_f;
    char	fzero;
    int		prec;
    int		fld_size;
}		t_opt;

int	ft_printf(const char *format, ...);
int	ft_get_args(va_list ap, char **split_format);
char	**ft_split_args(const char *format);
int	ft_parse_command(va_list ap, char *cmd);
int	ft_print_command(va_list ap, t_opt *options);
t_opt	*ft_init_struct(void);
int	ft_get_prec(char *cmd, int *index, va_list ap);
void	ft_get_field(char *cmd, int *ind, t_opt *options, va_list ap);

/*
** CHANGE TO_PRINT
*/

char	*ft_change_field_size(char *to_print, t_opt *options);
char	*ft_change_precision(char *to_print, t_opt *options);
char	*ft_change_precptr(char *to_print, int prec, int size);
char	*ft_change_hash(char *to_print, t_opt *options);
char	*ft_change_plus(char *to_print, t_opt *options);

/*
** CONVERSION
*/

char	*ft_conv_sigdec(va_list ap);
char	*ft_conv_str(va_list ap);
char	*ft_conv_unsigchar(va_list ap);
char	*ft_conv_unsigdec(va_list ap);
char	*ft_conv_octal(va_list ap);
char	*ft_conv_hexa(va_list ap);
char	*ft_conv_ptr(va_list ap);
int	ft_conv_no(char *cmd, va_list ap);
int	ft_aff_space(int ret, char *cmd, int *ind);
int	ft_aff_plus(int ret, char *cmd, int *ind);

#endif
