/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:57:57 by cmaxime           #+#    #+#             */
/*   Updated: 2019/01/29 10:06:20 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s1, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_realloc(char *s1, char const *s2);
int				ft_pow(int nb, int pow);
void			**ft_newmatrix(size_t x, size_t y, size_t size);
int				ft_tablen(char **tab);
void			ft_deltab(char **tab);
int				ft_in(char c, char *str);
int				ft_round(double nb);
char			*ft_ftoa(double nb, int precision);
double			ft_atof(char *str);
double			ft_sqrtof(double nb, size_t precision);
double			ft_powof(double nb, int exp);
double			ft_dabs(double nb);
int				ft_degal(double nb, double value);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_list_pushback(t_list **front, t_list *list);

typedef struct	s_ulist
{
	void			*content;
	size_t			content_size;
	struct s_ulist	*next;
	struct s_ulist	*prev;
}				t_ulist;

t_ulist			*ft_ulstnew(void const *content, size_t content_size);
void			ft_ulstadd_head(t_ulist **alst, t_ulist *new);
void			ft_ulstadd_tail(t_ulist **alst, t_ulist *new);
void			ft_ulstdel(t_ulist **alst, void (*del)(void*, size_t));
void			ft_ulstdelone(t_ulist **alst, void (*del)(void*, size_t));
t_ulist			*ft_ulstset_head(t_ulist *alst);
t_ulist			*ft_ulstset_tail(t_ulist *alst);
size_t			ft_ulstsize(t_ulist *alst);
size_t			ft_ulsttsize(t_ulist *alst);

int				get_next_line(int fd, char **line);

/*
** PRINFT
*/

typedef enum	e_type
{
	T_NONE = 0,
	T_HH,
	T_LL,
	T_H,
	T_L,
	T_Z,
	T_J
}				t_type;

typedef struct	s_print
{
	char		*buff;
	int			len;
	int			pib;
	int			ret;
	int			prev;
	int			hash;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			size;
	int			precision;
	t_type		modifier;
	char		conv;
	char		padding[3];
	int			force_h;
}				t_print;

typedef struct	s_cnv
{
	char		*cnv;
	t_print		(*f)(va_list ap, t_print p);
}				t_cnv;

typedef struct	s_op
{
	char		*op;
	t_print		(*f)(char *str, int *i, t_print p);
}				t_op;

int				ft_printf(const char *format, ...);
char			*ft_ltoa(uintmax_t n, size_t base);
char			*ft_ldtoa(long double n, int prec);
double			ft_powneg(int nb, int pow);
char			*ft_ldtoa_e(long double n, int prec);
t_print			pf_extractflag(char *str, int *i, t_print p);
t_print			pf_init_t_print(void);
t_print			pf_reinit_t_print(t_print p);
t_print			pf_update_t_print(char *str, int pos, t_print p);
t_print			pf_modifier_update(t_print p);
t_print			pf_collapse_buff(char *str, t_print p);
t_print			pf_collapse_char(char *str, int lenght, t_print p);
t_print			pf_flush_buff(t_print p);
t_print			pf_output_buff(t_print p);
int				pf_cmpchr(char *list, char c);
wchar_t			pf_check_mb_cur_max(void);
uintmax_t		pf_va_arg_int(va_list ap, t_print p);
uintmax_t		pf_va_arg_uint(va_list ap, t_print p);
void			*pf_va_arg_ptr(va_list ap, t_print p);
double			pf_va_arg_dec(va_list ap, t_print p);
wchar_t			pf_va_arg_chr(va_list ap);
char			*pf_get_hexa_htag(void);
char			*pf_get_octa_htag(void);
char			*pf_add_hash(char *buff, t_print p);
char			*pf_add_precision(char *buff, t_print p);
char			*pf_add_size(char *buff, t_print p, int signe);
char			*pf_add_size_chr(char *buff, int *lenght, t_print p);
char			*pf_check_val_zero_exception(char *buff, uintmax_t n);
char			*ft_realloc_mem(char *s1, char const *s2,
		size_t len1, size_t len2);
char			**pf_get_list_flag(void);
t_op			*pf_get_op(void);
t_cnv			*pf_get_cnv(void);
char			*pf_wchar_to_char(wchar_t wc, int *lenght);
t_print			pf_op_hash(char *str, int *i, t_print p);
t_print			pf_op_zero(char *str, int *i, t_print p);
t_print			pf_op_space(char *str, int *i, t_print p);
t_print			pf_op_min(char *str, int *i, t_print p);
t_print			pf_op_plus(char *str, int *i, t_print p);
t_print			pf_op_size(char *str, int *i, t_print p);
t_print			pf_op_precision(char *str, int *i, t_print p);
t_print			pf_op_modifier(char *str, int *i, t_print p);
t_print			pf_op_conv(char *str, int *i, t_print p);
t_print			pf_arg_int(va_list ap, t_print p);
t_print			pf_arg_flt(va_list ap, t_print p);
t_print			pf_arg_uint(va_list ap, t_print p);
t_print			pf_arg_str(va_list ap, t_print p);
t_print			pf_arg_chr(va_list ap, t_print p);
t_print			pf_arg_ptr(va_list ap, t_print p);
t_print			pf_arg_arg(va_list ap, t_print p);
t_print			pf_arg_def(va_list ap, t_print p);

#endif
