#include "ft_printf.h"

#include <stdio.h>

int	main(void)
{
    ft_putendl("Le mien:");
    ft_printf("Bla bla %-+03d", 0);
    ft_putchar('\n');
    ft_putendl("Le vrai:");
    printf("Bla bla %-+03d", 0);
    return (0);
}
