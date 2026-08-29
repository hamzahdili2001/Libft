#include "libft.h"

char	*ft_strncat(char *dest, const char *src, t_uint n)
{
	t_uint	i;
	char	*base_dest;

	base_dest = dest;
	while (*dest)
		dest++;
	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (base_dest);
}
