#include "libft.h"

void	test(char *name, int passed)
{
	if (passed)
	{
		ft_putstr("✅ ");
		ft_putstr((char *)name);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("❌ ");
		ft_putstr((char *)name);
		ft_putchar('\n');
	}
}

int	main(void)
{
	test_strings();
	test_ctype();
	test_stdlib();
}
