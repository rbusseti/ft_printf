#include "ft_printf.h"

#include <stdio.h>

int	main(void)
{
    ft_putendl("Le mien:");
    ft_printf("Bla bla %010p", (void*)30);
    ft_putchar('\n');
    ft_putendl("Le vrai:");
    printf("Bla bla %010p", (void*)30);
    return (0);
}
