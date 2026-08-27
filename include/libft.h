#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
typedef unsigned int	t_uint;

t_uint					ft_strlen(char *str);
int						ft_putchar(char c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, t_uint n);
int						ft_memcmp(const void *s1, const void *s2, t_uint n);
void					ft_putstr(char *str);
void					*ft_memset(void *s, int c, t_uint n);
void					*ft_memcpy(void *dest, const void *src, t_uint n);
void					*ft_memmove(void *dest, const void *src, t_uint n);
void					*ft_memchr(const void *s, int c, t_uint n);
void					*ft_memccpy(void *dest, const void *src, int c,
							t_uint n);
void					ft_bzero(void *s, t_uint n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, t_uint n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(char *haystack, char *needle);
char					*ft_strdup(const char *s);
#endif
