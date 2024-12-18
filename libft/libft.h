/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 10:09:46 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/17 12:13:24 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <complex.h>

size_t			ft_strlen(const char *src);
long int		ft_strtol(const char *str, char **endptr, int base);
double			ft_strtod(const char *str, char **endptr);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isspace(char ch);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			*ft_memset(void *dest, int c, size_t n );
void			ft_bzero(void *dest, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *src, int c, size_t n);
int				ft_memcmp(const void *src1, const void *src2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *src, int c);
char			*ft_strrchr(const char *src, int c);
char			*ft_strnstr(const char *src, const char *sub, size_t n);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_strcmp(const char *str1, const char *str2);
size_t			ft_strlcpy(char	*dest, const char *src, size_t destsize);
size_t			ft_strlcat(char	*dest, const char *src, size_t destsize);
int				ft_atoi(const char *str);
float			ft_atof(const char *str);
double complex	ft_atoc(const char *str);
void			*ft_calloc(size_t m, size_t n);
char			*ft_strdup(const char *str);
char			*ft_substr(const char *src, unsigned int start, size_t len);
char			*ft_strjoin(const char *str1, const char *str2);
char			*ft_strjoin_with(char *s1, char *s2, char c);
char			*ft_strtrim(const char *src, const char *set);
char			**ft_split(const char *src, char c);
char			*ft_itoa(int i);
char			*ft_strmapi(const char *str, char (*fn)(unsigned int, char));
ssize_t			ft_putchar_fd(char ch, int fd);
void			ft_striteri(char *str, void (*fn)(unsigned int, char *));
ssize_t			ft_putstr_fd(char *str, int fd);
ssize_t			ft_putendl_fd(char *str, int fd);
ssize_t			ft_putnbr_fd(int n, int fd);

#endif
