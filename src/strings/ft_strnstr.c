#include "libft.h"

/* this is a Bonus function does not exist in C standard lib */
char	*ft_strnstr(const char *haystack, const char *needle, t_uint len)
{
	t_uint	i;
	t_uint	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && (i + j) < len && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
