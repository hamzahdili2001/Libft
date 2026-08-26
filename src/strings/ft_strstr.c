#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	char	*n;
	char	*ht;

	if (*needle == '\0')
		return (haystack);
	while (*haystack)
	{
		n = needle;
		ht = haystack;
		while (*ht && *n && (*n == *ht))
		{
			ht++;
			n++;
		}
		if (*n == '\0')
			return (haystack);
		haystack++;
	}
	return (NULL);
}
