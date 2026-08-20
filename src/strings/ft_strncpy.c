#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, t_uint n)
{
	t_uint	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
