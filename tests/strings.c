#include "libft.h"
#include <assert.h>
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

int	test_ft_strcat(char *s1, char *s2)
{
	char	buff_1[100];
	char	buff_2[100];
	char	*ret1;

	strcpy(buff_1, s1);
	strcpy(buff_2, s1);
	ret1 = ft_strcat(buff_1, s2);
	strcat(buff_2, s2);
	if (strcmp(buff_1, buff_2) != 0)
		return (0);
	if (ret1 != buff_1)
		return (0);
	return (1);
}

int	same_sign(int a, int b)
{
	if (a == 0 && b == 0)
		return (1);
	if (a > 0 && b > 0)
		return (1);
	if (a < 0 && b < 0)
		return (1);
	return (0);
}

int	test_ft_strcmp(char *s1, char *s2)
{
	return (same_sign(ft_strcmp(s1, s2), strcmp(s1, s2)));
}

int	test_ft_strncmp(char *s1, char *s2, t_uint n)
{
	return (same_sign(ft_strncmp(s1, s2, n), strncmp(s1, s2, n)));
}

int	test_ft_memset(char *content, int c, size_t n)
{
	char	buff_1[100];
	char	buff_2[100];
	void	*ret1;

	memset(buff_1, 'Z', 100);
	memset(buff_2, 'Z', 100);
	strcpy(buff_1, content);
	strcpy(buff_2, content);
	ret1 = ft_memset(buff_1, c, n);
	memset(buff_2, c, n);
	if (memcmp(buff_1, buff_2, 100) != 0)
		return (0);
	if (ret1 != buff_1)
		return (0);
	return (1);
}

int	test_ft_memcpy(char *content, size_t n)
{
	char	buff_1[100];
	char	buff_2[100];
	void	*ret1;

	memset(buff_1, 'Z', 100);
	memset(buff_2, 'Z', 100);
	strcpy(buff_1, content);
	strcpy(buff_2, content);
	ret1 = ft_memcpy(buff_1 + 20, content, n);
	memcpy(buff_2 + 20, content, n);
	if (memcmp(buff_1, buff_2, 100) != 0)
		return (0);
	if (ret1 != buff_1 + 20)
		return (0);
	return (1);
}

int	test_ft_memmove_overlap_forward(void)
{
	char	buf1[20] = "hello world testing";
	char	buf2[20] = "hello world testing";

	ft_memmove(buf1 + 2, buf1, 10);
	memmove(buf2 + 2, buf2, 10);
	return (memcmp(buf1, buf2, 20) == 0);
}

int	test_ft_memmove_overlap_backward(void)
{
	char	buf1[20] = "hello world testing";
	char	buf2[20] = "hello world testing";

	ft_memmove(buf1, buf1 + 2, 10);
	memmove(buf2, buf2 + 2, 10);
	return (memcmp(buf1, buf2, 20) == 0);
}

int	test_ft_memmove_n_zero(void)
{
	char	buf1[20] = "hello world testing";
	char	buf2[20] = "hello world testing";
	void	*ret1;

	ret1 = ft_memmove(buf1, buf1 + 5, 0);
	memmove(buf2, buf2 + 5, 0);
	if (memcmp(buf1, buf2, 20) != 0)
		return (0);
	if (ret1 != buf1)
		return (0);
	return (1);
}

int	test_ft_memmove_no_overlap(void)
{
	char	buf1[20] = "hello world testing";
	char	buf2[20] = "hello world testing";
	char	src[6] = "abcde";

	ft_memmove(buf1 + 15, src, 5);
	memmove(buf2 + 15, src, 5);
	return (memcmp(buf1, buf2, 20) == 0);
}

int	main(void)
{
	/* ft_strlen */
	ft_putstr(" TEST: [ft_strlen]\n");
	test("ft_strlen  -> empty", ft_strlen("") == strlen(""));
	test("ft_strlen  -> str", ft_strlen("hello") == strlen("hello"));
	/* ft_strcpy */
	ft_putstr(" TEST: [ft_strcpy]\n");
	test("ft_strcpy  -> empty ", test_ft_strcpy(""));
	test("ft_strcpy  -> str ", test_ft_strcpy("this is a test"));
	/* ft_strncpy */
	ft_putstr(" TEST: [ft_strncpy]\n");
	test("ft_strncpy -> src short", test_ft_strncpy("hi", 10));
	test("ft_strncpy -> src long", test_ft_strncpy("hello world", 5));
	test("ft_strncpy -> n == 0", test_ft_strncpy("hello", 0));
	test("ft_strncpy -> exact len", test_ft_strncpy("abc", 3));
	/* ft_strcat */
	ft_putstr(" TEST: [ft_strcat]\n");
	test("ft_strcat  -> basic", test_ft_strcat("hello ", "world"));
	test("ft_strcat  -> empty src", test_ft_strcat("hello", ""));
	test("ft_strcat  -> empty dest", test_ft_strcat("", "world"));
	/* ft_strcmp */
	ft_putstr(" TEST: [ft_strcmp]\n");
	test("ft_strcmp -> prefix shorter", test_ft_strcmp("hi", "hello"));
	test("ft_strcmp -> prefix longer", test_ft_strcmp("hello", "hi"));
	test("ft_strcmp -> equal", test_ft_strcmp("hello", "hello"));
	test("ft_strcmp -> s1 < s2", test_ft_strcmp("abc", "abd"));
	test("ft_strcmp -> s1 > s2", test_ft_strcmp("abd", "abc"));
	/* ft_strncmp */
	ft_putstr(" TEST: [ft_strncmp]\n");
	test("ft_strncmp -> equal, full compare", test_ft_strncmp("hello", "hello",
			5));
	test("ft_strncmp -> equal, n larger than strings", test_ft_strncmp("hi",
			"hi", 100));
	test("ft_strncmp -> equal within n, differ after", test_ft_strncmp("hello",
			"help", 3));
	test("ft_strncmp -> differ within n", test_ft_strncmp("hello", "help", 4));
	test("ft_strncmp -> n == 0", test_ft_strncmp("abc", "xyz", 0));
	test("ft_strncmp -> n == 0, one empty", test_ft_strncmp("", "xyz", 0));
	test("ft_strncmp -> both empty", test_ft_strncmp("", "", 5));
	test("ft_strncmp -> s1 shorter than n", test_ft_strncmp("hi", "hello", 5));
	test("ft_strncmp -> s2 shorter than n", test_ft_strncmp("hello", "hi", 5));
	test("ft_strncmp -> n == 1", test_ft_strncmp("apple", "avocado", 1));
	/* strchr */
	ft_putstr(" TEST: [ft_strchr]\n");
	test("ft_strchr -> found first char", ft_strchr("hello",
			'h') == strchr("hello", 'h'));
	test("ft_strchr -> found middle char", ft_strchr("hello",
			'l') == strchr("hello", 'l'));
	test("ft_strchr -> found last char", ft_strchr("hello",
			'o') == strchr("hello", 'o'));
	test("ft_strchr -> not found", ft_strchr("hello", 'z') == strchr("hello",
			'z'));
	test("ft_strchr -> find null terminator", ft_strchr("hello",
			'\0') == strchr("hello", '\0'));
	test("ft_strchr -> empty string, char not present", ft_strchr("",
			'a') == strchr("", 'a'));
	test("ft_strchr -> empty string, find null", ft_strchr("",
			'\0') == strchr("", '\0'));
	test("ft_strchr -> repeated char, finds first occurrence",
		ft_strchr("banana", 'a') == strchr("banana", 'a'));
	test("ft_strchr -> single character string, match", ft_strchr("x",
			'x') == strchr("x", 'x'));
	test("ft_strchr -> single character string, no match", ft_strchr("x",
			'y') == strchr("x", 'y'));
	/* strrchr */
	ft_putstr(" TEST: [ft_strrchr]\n");
	test("ft_strrchr -> found, single occurrence", ft_strrchr("hello",
			'h') == strrchr("hello", 'h'));
	test("ft_strrchr -> found, multiple occurrences", ft_strrchr("banana",
			'a') == strrchr("banana", 'a'));
	test("ft_strrchr -> not found", ft_strrchr("hello", 'z') == strrchr("hello",
			'z'));
	test("ft_strrchr -> find null terminator", ft_strrchr("hello",
			'\0') == strrchr("hello", '\0'));
	test("ft_strrchr -> empty string, char not present", ft_strrchr("",
			'a') == strrchr("", 'a'));
	test("ft_strrchr -> empty string, find null", ft_strrchr("",
			'\0') == strrchr("", '\0'));
	test("ft_strrchr -> last char in string", ft_strrchr("hello",
			'o') == strrchr("hello", 'o'));
	/* ft_strstr */
	ft_putstr(" TEST: [ft_strstr]\n");
	test("ft_strstr -> found at start", ft_strstr("hello world",
			"hello") == strstr("hello world", "hello"));
	test("ft_strstr -> found in middle", ft_strstr("hello world",
			"wor") == strstr("hello world", "wor"));
	test("ft_strstr -> not found", ft_strstr("hello world",
			"xyz") == strstr("hello world", "xyz"));
	test("ft_strstr -> needle longer than haystack", ft_strstr("hi",
			"hello") == strstr("hi", "hello"));
	test("ft_strstr -> empty needle, non-empty haystack", ft_strstr("hello",
			"") == strstr("hello", ""));
	test("ft_strstr -> empty haystack, non-empty needle", ft_strstr("",
			"hi") == strstr("", "hi"));
	test("ft_strstr -> both empty", ft_strstr("", "") == strstr("", ""));
	test("ft_strstr -> needle equals haystack", ft_strstr("test",
			"test") == strstr("test", "test"));
	/* ft_memset */
	ft_putstr(" TEST: [ft_memset]\n");
	test("ft_memset -> basic", test_ft_memset("hello world", 'x', 5));
	test("ft_memset -> n == 0", test_ft_memset("hello", 'x', 0));
	test("ft_memset -> n larger than content", test_ft_memset("hi", 'x', 20));
	test("ft_memset -> zero fill", test_ft_memset("hello", 0, 5));
	/* ft_memcpy */
	ft_putstr(" TEST: [ft_memcpy]\n");
	test("ft_memcpy -> basic", test_ft_memcpy("hello", 5));
	test("ft_memcpy -> n == 0", test_ft_memcpy("hello", 0));
	test("ft_memcpy -> partial copy", test_ft_memcpy("hello world", 5));
	test("ft_memcpy -> single byte", test_ft_memcpy("x", 1));
	/*ft_memmove */
	ft_putstr(" TEST: [ft_memmove]\n");
	test("ft_memmove -> dest after src (overlap)",
		test_ft_memmove_overlap_forward());
	test("ft_memmove -> dest before src (overlap)",
		test_ft_memmove_overlap_backward());
	test("ft_memmove -> n == 0", test_ft_memmove_n_zero());
	test("ft_memmove -> non-overlapping", test_ft_memmove_no_overlap());
	/* ft_memcmp */
	ft_putstr(" TEST: [ft_memcmp]\n");
	test("ft_memcmp -> equal", ft_memcmp("hello", "hello", 5) == memcmp("hello",
			"hello", 5));
	test("ft_memcmp -> differ early", ft_memcmp("abc", "abd",
			3) == memcmp("abc", "abd", 3));
	test("ft_memcmp -> differ mid", ft_memcmp("aXc", "aYc", 3) == memcmp("aXc",
			"aYc", 3));
	test("ft_memcmp -> n == 0", ft_memcmp("abc", "xyz", 0) == memcmp("abc",
			"xyz", 0));
	test("ft_memcmp -> n smaller than actual diff position", ft_memcmp("abcXX",
			"abcYY", 3) == memcmp("abcXX", "abcYY", 3));
	/* ft_memchr */
	ft_putstr(" TEST: [ft_memchr]\n");
	test("ft_memchr -> found early", ft_memchr("hello", 'h',
			5) == memchr("hello", 'h', 5));
	test("ft_memchr -> found mid", ft_memchr("hello", 'l', 5) == memchr("hello",
			'l', 5));
	test("ft_memchr -> not found", ft_memchr("hello", 'z', 5) == memchr("hello",
			'z', 5));
	test("ft_memchr -> not found within n (found further, ignored)",
		ft_memchr("hello", 'o', 3) == memchr("hello", 'o', 3));
	test("ft_memchr -> n == 0", ft_memchr("hello", 'h', 0) == memchr("hello",
			'h', 0));
	test("ft_memchr -> find embedded null byte", ft_memchr("ab\0cd", '\0',
			5) == memchr("ab\0cd", '\0', 5));
	return (0);
}
