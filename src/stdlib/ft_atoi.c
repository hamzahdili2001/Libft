#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if ((*nptr == '+' || *nptr == '-'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		if (result > (INT_MAX - (*nptr - '0')) / 10)
			return (sign == 1 ? INT_MAX : INT_MIN);
		result = (result * 10) + *nptr - '0';
		nptr++;
	}
	return (result * sign);
}
