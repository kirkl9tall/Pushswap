/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abismail <abismail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:27:12 by abismail          #+#    #+#             */
/*   Updated: 2025/03/02 16:45:07 by abismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list *heada)
{
	void	*tmp_data;

	if (heada == NULL || heada->next == NULL)
		return ;
	tmp_data = heada->data;
	heada->data = heada->next->data;
	heada->next->data = tmp_data;
	write(1, "sa\n", 3);
}

void	pa(t_list **heada, t_list **headb)
{
	t_list	*tmp;

	if (headb == NULL || *headb == NULL)
		return ;
	tmp = *headb;
	*headb = (*headb)->next;
	tmp->next = *heada;
	*heada = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_list **heada, t_list **headb)
{
	t_list	*tmp;

	if (heada == NULL || *heada == NULL)
		return ;
	tmp = *heada;
	*heada = (*heada)->next;
	tmp->next = *headb;
	*headb = tmp;
	write(1, "pb\n", 3);
}

void	ra(t_list **heada)
{
	t_list	*tmp;
	t_list	*last;

	if (*heada == NULL || (*heada)->next == NULL)
		return ;
	tmp = *heada;
	*heada = (*heada)->next;
	tmp->next = NULL;
	last = *heada;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	write(1, "ra\n", 3);
}

void	rra(t_list **heada)
{
	t_list	*last;
	t_list	*second_last;

	if (*heada == NULL || (*heada)->next == NULL)
		return ;
	second_last = NULL;
	last = *heada;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *heada;
	*heada = last;
	write(1, "rra\n", 4);
}
