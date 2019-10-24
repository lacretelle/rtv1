#include "rtv1.h"
#include "parser.h"

static void add_pos(void* obj, void* content)
{
    t_rtsphere  *sph;

    sph = (t_rtsphere*)obj;
    ft_memcpy(sph->pos, content, sizeof(t_vec3));
}

static void add_rayon(void* obj, void* content)
{
    t_rtsphere  *sph;

    sph = (t_rtsphere*)obj;
    ft_memcpy(&(sph->rayon), content, sizeof(double));
}

static void add_color(void* obj, void* content)
{
    t_rtsphere  *sph;

    sph = (t_rtsphere*)obj;
    ft_memcpy(&(sph->color), content, sizeof(int));
}

int  build_sphere(void* obj, void *content, t_eval id, const char *key)
{
    t_parser_builder opt[3] = {
        {"origin", e_vec3, &add_pos},
        {"rayon", e_scalar, &add_rayon},
        {"color", e_hexa, &add_color},
    };
    size_t          i;

    if (content == NULL)
        return (-1);
    i = 0;
    while (i < 3)
    {
        if (0 == ft_strcmp(opt[i].key, key))
            break;
        ++i;
    }
    if (i == 3 || id != opt[i].id)
        return (-1);
    opt[i].f(obj, content);
    return (0);
}