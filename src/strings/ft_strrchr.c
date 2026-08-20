#include <libft.h>
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	i = 0;
	ptr = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			ptr = &s[i];
		i++;
	}
	if ((unsigned char)c == '\0')
		ptr = &s[i];
	return ((char *)ptr);
}
