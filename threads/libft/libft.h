/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:47:13 by hescoval          #+#    #+#             */
/*   Updated: 2023/12/12 16:40:27 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <ctype.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void		free_split(char **strs);
int			count_in(char *str, char c);
long long	ft_atol(const char *nptr);
int			ft_atoi(const char *nptr);
int			ft_isalnum(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_memset(void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_isalpha(int c);
int			ft_isascii(int c);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
int			ft_isprint(int c);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		ft_putchar_fd(char c, int fd);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstadd_back(t_list **lst, t_list *new);
int 		ft_max(int a, int b);
int			ft_abs(int num);
int			ft_min(int a, int b);

void	p_char(va_list args, int *printed);
void	p_deci(va_list args, int *printed, char flag);
void	p_hex(va_list args, int *printed, char flag);
void	p_module(int *printed);
void	p_str(va_list args, int *printed);
int		ft_printf(const char *str, ...);

int		ft_strcontains(char *s, char c);
char	*ft_strcpy_nl(char *dest, char *src, int nl_stop);
char	*ft_strjoin_special(char *s1, char *s2);
char	*get_next_line(int fd);

#endif