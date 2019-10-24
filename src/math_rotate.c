#include "rtv1.h"
#include <math.h>

double	degre2rad(double angle)
{
    return (angle * M_PI / 180.0);
}

double	rad2degre(double angle)
{
    return (angle * 180.0 / M_PI);
}

void    vec3_copy(t_vec3 dest, t_vec3 src)
{
    ft_memcpy(dest, src, sizeof(t_vec3));
}

void    rotate_xyz(t_vec3 dest, t_vec3 orig, double yaw, double pitch)
{
    t_vec3  tmp;

    vec3_copy(tmp, orig);
    tmp[0] = tmp[0] * cos(yaw) - tmp[2] * sin(yaw);
    tmp[2] = tmp[2] * cos(yaw) + tmp[0] * sin(yaw);
    tmp[1] = tmp[1] * cos(pitch) - tmp[2] * sin(pitch);
    tmp[2] = tmp[2] * cos(pitch) + tmp[1] * sin(pitch);
    vec3_copy(dest, tmp);
}