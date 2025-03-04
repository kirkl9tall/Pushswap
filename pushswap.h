/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abismail <abismail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:27:09 by abismail          #+#    #+#             */
/*   Updated: 2025/03/04 19:48:45 by abismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	void			*data;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
char				*ft_strcat(char *dest, const char *src);
int					counter_args(int argc, char *argv[]);
char				**ft_split(char *s, char c);
char				*prepare_str(int argc, char *argv[]);
int					ft_atoi(const char *nptr, t_list *heada, char **tab);
t_list				*ft_lstnew(int content);
void				ft_lstclear(t_list **lst);
void				sa(t_list *heada);
void				pa(t_list **heada, t_list **headb);
void				pb(t_list **heada, t_list **headb);
void				ra(t_list **heada);
void				rra(t_list **heada);
void				sort2(t_list *heada);
void				sort3(t_list **heada, t_list **headb);
void				sort4(t_list **heada, t_list **headb);
void				sort5(t_list **heada, t_list **headb);
void				radix(t_list **heada, t_list **headb, int q);
int					check_bits(int q);
int					calc_exit(t_list *head, t_list *min);
void				free_tab(char **tab);
void				list_assign(char **tab, t_list *heada);
t_list				*list_create(char **tab);
void				check_list(t_list *heada);
int					indexing(t_list *heada);
void				choice(t_list **heada, t_list **headb, int q);
int					check_sort(t_list *heada);
int					atoi_check(char nptr, int signe, int num);

#endif