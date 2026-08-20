#ifndef LIBFT_H
# define LIBFT_H

typedef unsigned int	t_uint;

t_uint					ft_strlen(char *str);
int						ft_putchar(char c);
void					ft_putstr(char *str);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, t_uint n);
char					*ft_strcat(char *dest, const char *src);
#endif
