#ifndef LIBFT_H
# define LIBFT_H

typedef unsigned int	t_uint;

t_uint					ft_strlen(char *str);
int						ft_putchar(char c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, t_uint n);
void					ft_putstr(char *str);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, t_uint n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strchr(const char *s, int c);
#endif
