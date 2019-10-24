#include <fcntl.h>
#include "parser.h"
#include "rtv1.h"


static int  process1param(void *obj, char **tmp, t_builder f)
{
    static t_proc   *opt;
    size_t  i;

    opt = params_definition();
    i = 0;
    while (i < 7)
    {
        if (0 == ft_strcmp(opt[i].key, tmp[0]))
            break;
        ++i;
    }
    if (i == 7)
        return (-1);
    f(obj, opt[i].process(tmp[1]), opt[i].type, tmp[0]);
    return (0);
}

static int  process_params_inner(void *obj, char **tmp, t_builder f)
{
    char    **tmp2;
    int     i;
    int     ret;

    if (ft_tablen(tmp) == 0)
        return (-1); // Error syntax
    i = 0;
    while (i < ft_tablen(tmp))
    {
        if (NULL == (tmp2 = value_split(tmp[i])))
            return (-1);
        ret = process1param(obj, tmp2, f);
        ft_deltab(tmp2);
        if (0 > ret)
            return (ret);
        ++i;
    }
    return (0);
}

static int  process_params(void *obj, char *str, t_builder f)
{
    char    **tmp;
    int     ret;

    if (NULL ==  (tmp = ft_strsplit(str, ';')))
        return (-1); // Error Malloc
    ret = process_params_inner(obj, tmp, f);
    ft_deltab(tmp);
    return (ret);
}

static int  pass(void *obj, void *content, t_eval id, const char *key)
{
    (void)obj;
    (void)key;
    (void)content;
    (void)id;
    return (0);
}

static int  process_line_inner(void **obj, char **tmp)
{
    static t_objbuilder opt[3] = {
        {"camera", &build_camera, &parser_alloccamera},
        {"sphere", &build_sphere, &parser_allocsphere},
        {"other", &pass, &parser_allocnull},
    };
    size_t              i;

    if (ft_tablen(tmp) != 2)
        return (-1); // Error syntax
    i = 0;
    while (i < (sizeof(opt) / sizeof(t_proc)))
    {
        if (0 == ft_strcmp(opt[i].key, tmp[0]))
            break;
        ++i;
    }
    if (i == (sizeof(opt) / sizeof(t_proc)))
        return (-1);
    if (NULL == (*obj = opt[i].getobj()))
        return (-1);
    process_params(*obj, tmp[1], opt[i].process);
    /* CHECK OBJECT */
    if (ft_strcmp(opt[i].key, "camera") == 0)
    {
        t_rtcamera  *cam = (t_rtcamera*)(*obj);
        ft_printf("Camera\n");
        ft_printf("origin: %f %f %f\n", cam->origin[0], cam->origin[1], cam->origin[2]);
        ft_printf("direction: %f %f %f\n", cam->dir[0], cam->dir[1], cam->dir[2]);
        ft_printf("focal: %f\n", cam->f);
        ft_printf("width: %f\n", cam->width);
        ft_printf("height: %f\n", cam->height);
    }
     if (ft_strcmp(opt[i].key, "sphere") == 0)
    {
        t_rtsphere  *sph = (t_rtsphere*)(*obj);
        ft_printf("Sphere\n");
        ft_printf("origin: %f %f %f\n", sph->pos[0], sph->pos[1], sph->pos[2]);
        ft_printf("focal: %f\n", sph->rayon);
        ft_printf("width: %lx\n", (size_t)(sph->color));
    }
    return (0);
}

static int  process_line(char *line)
{
    char    **tmp;
    int     ret;
    void    *obj;

    obj = NULL;
    if (NULL == (tmp = ft_strsplit(line, ':')))
        return (-1); // Error Malloc
    ret = process_line_inner(&obj, tmp);
    ft_deltab(tmp);
    if (ret >= 0)
    {
        // TODO: Add object to a list of items
        free(obj);
    }
    return (ret);
}

static void clear_line(char **line)
{
    if (NULL != *line)
        free(*line);
    *line = NULL;
}

int         load_scene_from_file(const char *path)
{
    int     fd;
    int     ret;
    char    *line;

    DEBUG("Loading scene from file");
    line = NULL;
    if (0 > (fd = open(path, O_RDONLY)))
        return (-1); // Error Open
    while (0 < (ret = get_next_line(fd, &line)))
    {
        if (NULL != line && 0 > process_line(line))
            return (-1); // Error
        clear_line(&line);
    }
    clear_line(&line);
    return (0); // No Error
}