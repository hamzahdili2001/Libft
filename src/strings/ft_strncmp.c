#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, t_uint n)
{
	t_uint	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((*s1 && *s2) && (*s1 == *s2) && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	return (*s1 - *s2);
}
