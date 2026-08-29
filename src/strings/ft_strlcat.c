#include "libft.h"

t_uint	ft_strlcat(char *dest, const char *src, t_uint size)
{
	t_uint	i;
	t_uint	space;
	t_uint	dest_len;
	t_uint	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (dest_len >= size)
		return (size + src_len);
	space = size - dest_len - 1;
	while (*dest)
		dest++;
	i = 0;
	while (i < space && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
