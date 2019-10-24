#include "parser.h"
#include "rtv1.h"

void    *parser_alloccamera(void)
{
    return (ft_memalloc(sizeof(t_rtcamera)));
}

void    *parser_allocsphere(void)
{
    return (ft_memalloc(sizeof(t_rtsphere)));
}


void    *parser_allocnull(void)
{
    return (NULL);
}