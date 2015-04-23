#include "ft_printf.h"

t_opt	*ft_init_struct(void)
{
    t_opt       *options;

    options = malloc(sizeof(*options));
    options->conv = 0;
    options->space = 0;
    options->d_mod = 0;
    options->p_zero = 0;
    options->error = 0;
    options->hash = 0;
    options->plus = 0;
    options->minus = 0;
    options->isprec = 0;
    options->prec = 0;
    options->fld_size = 0;
    options->fld_m = 0;
    options->m_minus = 0;
    options->zero_f = 0;
    options->fzero = 0;
    return (options);
}
