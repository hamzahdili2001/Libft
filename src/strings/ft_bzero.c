#include "libft.h"

void	ft_bzero(void *s, t_uint n)
{
	t_uint			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
		p[i++] = 0;
}
