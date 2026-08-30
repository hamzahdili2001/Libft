#include "libft.h"

double	ft_atof(const char *nptr)
{
	double	sign;
	double	fraction;
	double	result;

	sign = 1;
	fraction = 10;
	result = 0;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		result = result + (*nptr - '0') / fraction;
		fraction = fraction * 10;
		nptr++;
	}
	return (result * sign);
}
