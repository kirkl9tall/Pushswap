#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include  <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list
{
    int             index;
    void            *data;
    struct s_list   *next;
} t_list;


size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dest, const char *src);
int  counter_args( int argc, char *argv[]);
char	**ft_split(char *s, char c);
char *prepare_str(int argc, char *argv[]);
int ft_atoi(const char *nptr);
t_list	*ft_lstnew(int content);
void sa(t_list *heada);
void sb(t_list *headb);
void ss(t_list *heada, t_list *headb);
void pa(t_list **heada, t_list **headb);
void pb(t_list **heada, t_list **headb);
void ra(t_list **heada);
void rb(t_list **headb);
void rr(t_list **heada, t_list **headb);
void rra(t_list **heada);
void rrb(t_list **headb);
void rrr(t_list **heada, t_list **headb);

#endif