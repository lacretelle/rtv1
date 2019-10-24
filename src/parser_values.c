#include "parser.h"
#include "rtv1.h"

static void    *ft_memdup(const void* src, size_t len)
{
    unsigned char   *mem;
    mem = (unsigned char*)ft_memalloc(sizeof(unsigned char) * len);
    if (NULL == mem)
        return (NULL);
    mem = ft_memcpy(mem, src, len);
    return (mem);
}

void    *parse_scalar(char *str)
{
    double  val;

    if (0 > ft_isfloat(str))
        return (NULL);
    val = ft_atof(str);
    return (ft_memdup(&val, sizeof(double)));
}

void    *parse_hexa(char *str)
{
    static char base16[17] = "0123456789abcdef";
    size_t  color;
    size_t  i;

    if (ft_strlen(str) < 2 || str[0] != '0' || str[1] != 'x')
        return (NULL);
    str += 2;
    i = 0;
    while (str[i])
    {
        if (!ft_in(str[i], base16))
            return (NULL);
        ++i;
    }
    color = ft_atoiubase(str, base16);
    return (ft_memdup(&color, sizeof(size_t)));
}

void    *parse_vec3(char *str)
{
    t_vec3  val;
    size_t  i;
    char    **tmp;

    if (NULL == (tmp = ft_strsplit(str, ',')))
        return (NULL); // Error Malloc
    if (3 != ft_tablen(tmp))
    {
        ft_deltab(tmp);
        return (NULL); // Error Malloc
    }
    i = 0;
    while (i < 3)
    {
        if (0 > ft_isfloat(tmp[i]))
        {
            ft_deltab(tmp);
            return (NULL);
        }
        val[i] = ft_atof(tmp[i]);
        ++i;
    }
    ft_deltab(tmp);
    return (ft_memdup(&val, sizeof(t_vec3)));
}