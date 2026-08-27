#include "libft.h"

void	*ft_memset(void *s, int c, t_uint n)
{
	t_uint			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
