#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>

# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_get_args(va_list ap, char **split_format);

/*
**CONVERSION
*/

char	*ft_conv_sigdec(va_list ap);
char	*ft_conv_str(va_list ap);
char	*ft_conv_unsigchar(va_list ap);
char	*ft_conv_unsigdec(va_list ap);
char	*ft_conv_octal(va_list ap);

#endif
