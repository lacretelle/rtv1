#include "parser.h"

t_proc  *params_definition(void)
{
    static t_proc   opt[7] = {
        {"width", &parse_scalar, e_scalar},
        {"height", &parse_scalar, e_scalar},
        {"focal", &parse_scalar, e_scalar},
        {"rayon", &parse_scalar, e_scalar},
        {"color", &parse_hexa, e_hexa},
        {"origin", &parse_vec3, e_vec3},
        {"direction", &parse_vec3, e_vec3},
    };

    return (opt);
}
