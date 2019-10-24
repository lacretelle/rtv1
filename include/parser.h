#ifndef PARSER_H
# define PARSER_H

# include <stddef.h>

# define DEBUG(str) ft_putendl(str)

/*
** PARSER
*/

typedef enum    s_eval
{
    e_scalar,
    e_hexa,
    e_vec3,
    e_null,
}               t_eval;

typedef struct  s_proc
{
    char    *key;
    void*   (*process)(char*);
    t_eval  type;
}               t_proc;

typedef int (*t_builder)(void*, void*, t_eval, const char*);

typedef struct  s_objbuilder
{
    char    	*key;
    t_builder   process;
    void*   	(*getobj)(void);
}               t_objbuilder;

int				load_scene_from_file(const char *path);

size_t			ft_atoiubase(const char *str, const char *base);
int				ft_index(char c, const char *str);
int				ft_isfloat(char *str);
char			**value_split(char *str);

void     		*parse_scalar(char *str);
void    		*parse_vec3(char *str);
void    		*parse_hexa(char *str);

t_proc			*params_definition(void);

typedef struct  s_parser_builder
{
    char    *key;
    t_eval  id;
    void    (*f)(void*, void*);
}               t_parser_builder;

int				build_camera(void* obj, void *content, t_eval id, const char *key);
int             build_sphere(void* obj, void *content, t_eval id, const char *key);


void			*parser_alloccamera(void);
void            *parser_allocsphere(void);
void			*parser_allocnull(void);

#endif
