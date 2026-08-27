#include "libft.h"

void	*ft_memchr(const void *s, int c, t_uint n)
{
	t_uint				i;
	const unsigned char	*p;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
