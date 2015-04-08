#include "ft_printf.h"

#include <stdio.h>

int	main(void)
{
    ft_putendl("Le mien:");
    ft_printf("La premiere lettre est le %o", 666);
    ft_putchar('\n');
    ft_putendl("Le vrai:");
    printf("La premiere lettre est le %o", 666);
    return (0);
}
