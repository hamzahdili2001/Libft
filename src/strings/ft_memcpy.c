#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, t_uint n)
{
	t_uint				i;
	const unsigned char	*p1;
	unsigned char		*p2;

	p1 = (const unsigned char *)src;
	p2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		p2[i] = p1[i];
		i++;
	}
	return (dest);
}
