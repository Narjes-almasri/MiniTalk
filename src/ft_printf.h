#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *l, ...);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_start(va_list ap, char c);

/* Optional future function prototypes */
int		ft_p(unsigned long n);
int		ft_pointer(unsigned long n, int wonder);
int		ft_putunsignednbr(unsigned int m);

#endif
