/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abismail <abismail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:27:15 by abismail          #+#    #+#             */
/*   Updated: 2025/02/26 23:39:58 by abismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort2(t_list *heada)
{
	if (*(int *)heada->data > *(int *)heada->next->data)
		sa(heada);
}

void	sort3(t_list **heada, t_list **headb)
{
	t_list	*min;
	t_list	*trav;

	min = *heada;
	trav = *heada;
	while (trav)
	{
		if (*(int *)trav->data < *(int *)min->data)
			min = trav;
		trav = trav->next;
	}
	if (calc_exit(*heada, min) == 1)
		while (*(int *)(*heada)->data != *(int *)min->data)
			rra(heada);
	else
		while (*(int *)(*heada)->data != *(int *)min->data)
			ra(heada);
	pb(heada, headb);
	sort2(*heada);
	pa(heada, headb);
}

void	sort4(t_list **heada, t_list **headb)
{
	t_list	*min;
	t_list	*trav;

	trav = *heada;
	min = *heada;
	while (trav)
	{
		if (*(int *)trav->data < *(int *)min->data)
			min = trav;
		trav = trav->next;
	}
	if (calc_exit(*heada, min) == 1)
		while (*(int *)(*heada)->data != *(int *)min->data)
			rra(heada);
	else
		while (*(int *)(*heada)->data != *(int *)min->data)
			ra(heada);
	pb(heada, headb);
	sort3(heada, headb);
	pa(heada, headb);
}

void	sort5(t_list **heada, t_list **headb)
{
	t_list	*min;
	t_list	*trav;

	trav = *heada;
	min = *heada;
	while (trav)
	{
		if (*(int *)trav->data < *(int *)min->data)
			min = trav;
		trav = trav->next;
	}
	if (calc_exit(*heada, min) == 1)
		while (*(int *)(*heada)->data != *(int *)min->data)
			rra(heada);
	else
		while (*(int *)(*heada)->data != *(int *)min->data)
			ra(heada);
	pb(heada, headb);
	sort4(heada, headb);
	pa(heada, headb);
}

void	radix(t_list **heada, t_list **headb, int q)
{
	int	bits;
	int	bit;
	int	count;

	bits = check_bits(q);
	bit = 0;
	while (bit < bits)
	{
		count = q;
		while (count--)
		{
			if (((*heada)->index >> bit) & 1)
				ra(heada);
			else
				pb(heada, headb);
		}
		while (*headb)
			pa(heada, headb);
		bit++;
	}
}
