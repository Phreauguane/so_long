/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:38:10 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 00:32:23 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# define SPECS "cspdiuxX%*"
# define FLAGS "-0#. +"
# define SP_CHR 0
# define SP_STR 1
# define SP_PTR 2
# define SP_DEC 3
# define SP_INT 4
# define SP_UIN 5
# define SP_HEX 6
# define SP_CAP_HEX 7

typedef struct flags_s
{
	char	flags;
	char	spec;
	int		length;
	int		precision;
}	t_flags;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
void			ft_free_split(char **tab);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void*(*f)(void*), void(*del)(void*));
void			args_to_str(char **fmt, va_list params, char **str, int *l);
void			print_char(t_flags flags, char **str, char c, int *l);
void			print_str(t_flags flags, char **str, const char *s, int *l);
void			print_hex(t_flags f, char **s, unsigned long long i, int *l);
void			print_int(t_flags flags, char **str, long int i, int *l);
int				ft_printf(const char *fmt, ...);
char			*ft_strcat_malloc(char *dest, char *src);
char			*ft_straddchr(char *str, char c);
char			*ft_itoa_base(long long int n, char *base, int ptr);
void			add_pre(t_flags flags, char **str, unsigned long long i);
void			add_zer(t_flags flags, char **str, char *itoa_out);
char			*get_next_line(int fd);
char			*str_addc(char *str, char c);
int				stchr(char *s, char c);
char			*str_adds(char *str, char *s, size_t src_len);

#endif
