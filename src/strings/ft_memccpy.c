#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, t_uint n)
{
	unsigned char		*d;
	const unsigned char	*s;
	t_uint				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return ((d + i + 1));
		i++;
	}
	return (NULL);
}
