/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abismail <abismail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:27:18 by abismail          #+#    #+#             */
/*   Updated: 2025/02/27 14:25:08 by abismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = malloc(sizeof(int));
	if (!node->data)
		return (NULL);
	*(int *)node->data = content;
	node->next = NULL;
	node->index = 0;
	return (node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*ptr2;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		ptr2 = ptr->next;
		free(ptr->data);
		free(ptr);
		ptr = ptr2;
	}
	*lst = NULL;
}

void	free_tab(char **tab)
{
	char	**tmp;

	tmp = tab;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tab);
}

void	list_assign(char **tab, t_list *heada)
{
	int		i;
	t_list	*node;

	i = 0;
	while (tab[i])
	{
		node = ft_lstnew(ft_atoi(tab[i],heada,tab));
		if (node == NULL)
		{
			write(2, "Error\n", 6);
			return ;
		}
		node->next = heada;
		heada = node;
		i++;
	}
}

t_list	*list_create(char **tab)
{
	t_list	*heada;
	t_list	*tail;
	t_list	*node;
	int	i;

	heada = NULL;
	i = 0;
	while (tab[i])
	{
		node = ft_lstnew(ft_atoi(tab[i],heada,tab));
		if (node == NULL)
			return (write(2, "Error\n", 7), NULL);
		if (heada == NULL)
		{
			heada = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
		i++;
	}
	return (heada);
}
