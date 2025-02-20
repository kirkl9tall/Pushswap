#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

// typedef struct s_ps
// {
//     t_list *heada;
//     t_list *headb;
    
// } t_ps;
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dest, const char *src);
int  counter_args( int argc, char *argv[]);
char	**ft_split(char *s, char c);
int	ft_atoi(const char *nptr);
t_list	*ft_lstnew(int content);




#endif