#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

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

int	test_ft_strcpy(char *str)
{
	char	buff_1[100];
	char	buff_2[100];
	char	*ret1;

	ret1 = ft_strcpy(buff_1, str);
	strcpy(buff_2, str);
	if (strcmp(buff_1, buff_2) != 0)
		return (0);
	if (ret1 != buff_1)
		return (0);
	return (1);
}

int	test_ft_strncpy(char *str, t_uint n)
{
	char	buff_1[100];
	char	buff_2[100];
	char	*ret1;

	memset(buff_1, 'X', 100);
	memset(buff_2, 'X', 100);
	ret1 = ft_strncpy(buff_1, str, n);
	strncpy(buff_2, str, n);
	if (memcmp(buff_1, buff_2, n) != 0)
		return (0);
	if (ret1 != buff_1)
		return (0);
	return (1);
}

int	main(void)
{
	test("ft_strlen  -> empty", ft_strlen("") == strlen(""));
	test("ft_strlen  -> str", ft_strlen("hello") == strlen("hello"));
	test("ft_strcpy  -> empty ", test_ft_strcpy(""));
	test("ft_strcpy  -> str ", test_ft_strcpy("this is a test"));
	test("ft_strncpy -> src short", test_ft_strncpy("hi", 10));
	test("ft_strncpy -> src long", test_ft_strncpy("hello world", 5));
	test("ft_strncpy -> n == 0", test_ft_strncpy("hello", 0));
	test("ft_strncpy -> exact len", test_ft_strncpy("abc", 3));
	return (0);
}
