#include "rtv1.h"
#include "parser.h"

static void add_origin(void* obj, void* content)
{
    t_rtcamera  *camera;

    camera = (t_rtcamera*)obj;
    ft_memcpy(camera->origin, content, sizeof(t_vec3));
}

static void add_direction(void* obj, void* content)
{
    t_rtcamera  *camera;

    camera = (t_rtcamera*)obj;
    ft_memcpy(camera->dir, content, sizeof(t_vec3));
}

static void add_focal(void* obj, void* content)
{
    t_rtcamera  *camera;

    camera = (t_rtcamera*)obj;
    ft_memcpy(&(camera->f), content, sizeof(double));
}

static void add_width(void* obj, void* content)
{
    t_rtcamera  *camera;

    camera = (t_rtcamera*)obj;
    ft_memcpy(&(camera->width), content, sizeof(double));
}

static void add_height(void* obj, void* content)
{
    t_rtcamera  *camera;

    camera = (t_rtcamera*)obj;
    ft_memcpy(&(camera->height), content, sizeof(double));
}

int  build_camera(void* obj, void *content, t_eval id, const char *key)
{
    t_parser_builder opt[5] = {
        {"origin", e_vec3, &add_origin},
        {"direction", e_vec3, &add_direction},
        {"focal", e_scalar, &add_focal},
        {"width", e_scalar, &add_width},
        {"height", e_scalar, &add_height},
    };
    size_t          i;

    if (content == NULL)
        return (-1);
    i = 0;
    while (i < 5)
    {
        if (0 == ft_strcmp(opt[i].key, key))
            break;
        ++i;
    }
    if (i == 5 || id != opt[i].id)
        return (-1);
    opt[i].f(obj, content);
    return (0);
}