#include "libft.h"
#include <ctype.h>

int	same_bool(int a, int b)
{
	return ((a != 0) == (b != 0));
}

void	test_ctype(void)
{
	ft_putstr("|*----------------------*|\n");
	ft_putstr("|* TEST CTYPE FUNCTIONS *|\n");
	ft_putstr("|*----------------------*|\n");
	ft_putstr(" TEST: [ft_isdigit]\n");
	test("ft_isdigit -> digit", same_bool(ft_isdigit('5'), isdigit('5')));
	test("ft_isdigit -> non-digit", same_bool(ft_isdigit('a'), isdigit('a')));
	ft_putstr(" TEST: [ft_isspace]\n");
	test("ft_isspace -> space", same_bool(ft_isspace(' '), isspace(' ')));
	test("ft_isspace -> tab", same_bool(ft_isspace('\t'), isspace('\t')));
	test("ft_isspace -> non-space", same_bool(ft_isspace('x'), isspace('x')));
	ft_putstr(" TEST: [ft_isupper]\n");
	test("ft_isupper -> upper", same_bool(ft_isupper('A'), isupper('A')));
	test("ft_isupper -> lower", same_bool(ft_isupper('a'), isupper('a')));
	ft_putstr(" TEST: [ft_islower]\n");
	test("ft_islower -> lower", same_bool(ft_islower('a'), islower('a')));
	ft_putstr(" TEST: [ft_isalpha]\n");
	test("ft_isalpha -> letter", same_bool(ft_isalpha('Z'), isalpha('Z')));
	test("ft_isalpha -> digit", same_bool(ft_isalpha('5'), isalpha('5')));
	ft_putstr(" TEST: [ft_toupper]\n");
	test("ft_toupper -> lowercase in", same_bool(ft_toupper('a'),
			toupper('a')));
	test("ft_toupper -> already upper", same_bool(ft_toupper('A'),
			toupper('A')));
	test("ft_toupper -> non-letter", same_bool(ft_toupper('5'), toupper('5')));
	ft_putstr(" TEST: [ft_tolower]\n");
	test("ft_tolower -> uppercase in", same_bool(ft_tolower('A'),
			tolower('A')));
	ft_putstr(" TEST: [ft_isalnum]\n");
	test("ft_isalnum -> letter", same_bool(ft_isalnum('a'), isalnum('a')));
	test("ft_isalnum -> digit", same_bool(ft_isalnum('5'), isalnum('5')));
	test("ft_isalnum -> symbol", same_bool(ft_isalnum('!'), isalnum('!')));
	ft_putstr(" TEST: [ft_isascii]\n");
	test("ft_isascii -> in range", same_bool(ft_isascii(100), isascii(100)));
	test("ft_isascii -> out of range", same_bool(ft_isascii(200),
			isascii(200)));
	ft_putstr(" TEST: [ft_isprint]\n");
	test("ft_isprint -> printable", same_bool(ft_isprint('a'), isprint('a')));
	test("ft_isprint -> control char", same_bool(ft_isprint('\n'),
			isprint('\n')));
	test("ft_isprint -> space (edge of range)", same_bool(ft_isprint(' '),
			isprint(' ')));
}
