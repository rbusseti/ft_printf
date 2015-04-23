#include "ft_printf.h"

static int	ft_calc_size(const char *format)
{
    int		i;
    int		size;

    i = 0;
    size = 1;
    while (format[i])
    {
	if (format[i] == '%')
	    size++;
	i++;
    }
    return (size + 1);
}

static char	*ft_copy_segment(const char *s, int start, int end)
{
    char	*split;
    int		i;

    split = malloc(sizeof(char) * (end - start + 1));
    i = 0;
    while (start < end)
    {
	split[i] = s[start];
	start++;
	i++;
    }
    split[i] = '\0';
    return (split);
}

static char	*ft_get_segment(const char *s, int *index)
{
    int		i;
    int		save_i;

    i = *index;
    save_i = *index;
    if (s[i] != '%')
    {
	while (s[i] != '%')
	    i++;
    }
    else
    {
	i++;
	while (s[i] != 'd' && s[i] != 'i' && s[i] != 'u' && s[i] != 'o' && \
	    s[i] != 'x' && s[i] != 'p' && s[i] != 'c' && s[i] != 's' && \
	       s[i] != '%' && s[i] != '\0')
	    i++;
	if (s[i] != '\0')
	    i++;
    }
    *index = i;
    return (ft_copy_segment(s, save_i, i));
}

char		**ft_split_args(const char *format)
{
    int		i;
    int		j;
    char	**split_args;

    i = 0;
    j = 0;
    split_args = malloc(sizeof(char *) * ft_calc_size(format));
    while (format[i])
    {
	split_args[j] = ft_get_segment(format, &i);
	j++;
    }
    split_args[j] = '\0';
    return (split_args);
}
