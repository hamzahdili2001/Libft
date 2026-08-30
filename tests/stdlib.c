#include "libft.h"
#include <math.h>

int	test_ft_atoi(char *s)
{
	return (ft_atoi(s) == atoi(s));
}

int	test_ft_atol(char *s)
{
	return (ft_atol(s) == atol(s));
}

int	same_double(double a, double b)
{
	return (fabs(a - b) < 0.0001);
}

int	test_ft_atof(char *s)
{
	return (same_double(ft_atof(s), atof(s)));
}

void	test_stdlib(void)
{
	ft_putstr("|*-----------------------*|\n");
	ft_putstr("|* TEST STDLIB FUNCTIONS *|\n");
	ft_putstr("|*-----------------------*|\n");
	ft_putstr(" TEST: [ft_atoi]\n");
	test("ft_atoi -> basic positive", test_ft_atoi("123"));
	test("ft_atoi -> basic negative", test_ft_atoi("-123"));
	test("ft_atoi -> explicit plus sign", test_ft_atoi("+123"));
	test("ft_atoi -> leading whitespace", test_ft_atoi("   123"));
	test("ft_atoi -> leading tabs/newlines", test_ft_atoi("\t\n  456"));
	test("ft_atoi -> zero", test_ft_atoi("0"));
	test("ft_atoi -> negative zero", test_ft_atoi("-0"));
	test("ft_atoi -> stops at first non-digit", test_ft_atoi("123abc"));
	test("ft_atoi -> no digits at all", test_ft_atoi("abc"));
	test("ft_atoi -> empty string", test_ft_atoi(""));
	test("ft_atoi -> only whitespace", test_ft_atoi("   "));
	test("ft_atoi -> only a sign, no digits", test_ft_atoi("-"));
	test("ft_atoi -> sign then whitespace then digits", test_ft_atoi("-  123"));
	test("ft_atoi -> multiple signs", test_ft_atoi("--123"));
	test("ft_atoi -> leading zeros", test_ft_atoi("007"));
	test("ft_atoi -> INT_MAX exactly", test_ft_atoi("2147483647"));
	test("ft_atoi -> INT_MIN exactly", test_ft_atoi("-2147483648"));
	/*ft_atol*/
	ft_putstr(" TEST: [ft_atol]\n");
	test("ft_atol -> basic positive", test_ft_atol("123"));
	test("ft_atol -> basic negative", test_ft_atol("-123"));
	test("ft_atol -> explicit plus sign", test_ft_atol("+123"));
	test("ft_atol -> leading whitespace", test_ft_atol("   123"));
	test("ft_atol -> leading tabs/newlines", test_ft_atol("\t\n  456"));
	test("ft_atol -> zero", test_ft_atol("0"));
	test("ft_atol -> negative zero", test_ft_atol("-0"));
	test("ft_atol -> stops at first non-digit", test_ft_atol("123abc"));
	test("ft_atol -> no digits at all", test_ft_atol("abc"));
	test("ft_atol -> empty string", test_ft_atol(""));
	test("ft_atol -> only whitespace", test_ft_atol("   "));
	test("ft_atol -> only a sign, no digits", test_ft_atol("-"));
	test("ft_atol -> sign then whitespace then digits", test_ft_atol("-  123"));
	test("ft_atol -> multiple signs", test_ft_atol("--123"));
	test("ft_atol -> leading zeros", test_ft_atol("007"));
	test("ft_atol -> large value beyond int range", test_ft_atol("5000000000"));
	test("ft_atol -> large negative beyond int range",
		test_ft_atol("-5000000000"));
	/*ft_atof*/
	ft_putstr(" TEST: [ft_atof]\n");
	test("ft_atof -> basic integer", test_ft_atof("123"));
	test("ft_atof -> basic decimal", test_ft_atof("123.456"));
	test("ft_atof -> negative decimal", test_ft_atof("-0.5"));
	test("ft_atof -> positive sign", test_ft_atof("+42.5"));
	test("ft_atof -> leading whitespace", test_ft_atof("   3.14"));
	test("ft_atof -> zero", test_ft_atof("0"));
	test("ft_atof -> zero with decimal", test_ft_atof("0.0"));
	test("ft_atof -> negative zero", test_ft_atof("-0.0"));
	test("ft_atof -> trailing dot, no fraction digits", test_ft_atof("5."));
	test("ft_atof -> leading dot, no integer digits", test_ft_atof(".5"));
	test("ft_atof -> stops at non-numeric", test_ft_atof("12.5abc"));
	test("ft_atof -> no digits at all", test_ft_atof("abc"));
	test("ft_atof -> empty string", test_ft_atof(""));
	test("ft_atof -> only a dot", test_ft_atof("."));
	test("ft_atof -> many fractional digits", test_ft_atof("3.14159265"));
	test("ft_atof -> negative with many digits", test_ft_atof("-987.654321"));
}
