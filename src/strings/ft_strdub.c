#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	t_uint	size;
	t_uint	i;

	size = ft_strlen((char *)s) + 1;
	result = malloc(size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}
