#include "libft.h"

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == INT_MIN)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	ft_putchar(c);
}
