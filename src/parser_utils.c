#include "parser.h"
#include "libft.h"

char			**value_split(char *str)
{
    char    **tmp;
    size_t  len;

    if (NULL == (tmp = ft_strsplit(str, '(')))
        return (NULL); // Error Malloc
    if (ft_tablen(tmp) != 2)
    {
        ft_deltab(tmp);
        return (NULL);
    }
    len = ft_strlen(tmp[1]) - 1;
    while (len > 0 && (tmp[1][len] == ' ' || tmp[1][len] == '\t'))
        --len;
    if (len == 0 || tmp[1][len] != ')')
    {
        ft_deltab(tmp);
        return (NULL);
    }
    tmp[1][len] = '\0';
    return (tmp);
}

int				ft_isfloat(char *str)
{
	size_t	i;
	int		dot;

	i = 0;
	dot = 0;
	if (str[0] == '-')
		i++;
	while ('\0' != str[i])
	{
		if (1 != dot && str[i] == '.')
			dot = 1;
		else if (1 != ft_isdigit(str[i]))
			return (-1);
		++i;
	}
	return (0);
}

int     ft_index(char c, const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return ((int)i);
        ++i;
    }
    return (-1);
}

size_t		ft_atoiubase(const char *str, const char *base)
{
	size_t	i;
	size_t		nb;

	nb = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	while (ft_in(str[i], (char*)base))
	{
		nb = nb * (ft_strlen(base)) + ft_index(str[i], base);
		i++;
	}
	return (nb);
}