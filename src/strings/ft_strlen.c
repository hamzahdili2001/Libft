#include "libft.h"

t_uint	ft_strlen(char *str)
{
	t_uint	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
