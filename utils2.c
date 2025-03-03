/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abismail <abismail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:27:21 by abismail          #+#    #+#             */
/*   Updated: 2025/03/03 20:40:54 by abismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	calc_exit(t_list *head, t_list *min)
{
	t_list	*trav;
	int		toptomin;
	int		mintobot;

	trav = head;
	toptomin = 0;
	mintobot = 0;
	while (*(int *)trav->data != *(int *)min->data)
	{
		trav = trav->next;
		toptomin++;
	}
	while (trav->next != NULL)
	{
		trav = trav->next;
		mintobot++;
	}
	return (toptomin > mintobot);
}

int	check_bits(int q)
{
	int	bits;

	bits = 0;
	while (q)
	{
		q >>= 1;
		bits++;
	}
	return (bits);
}

void	choice(t_list **heada, t_list **headb, int q)
{
	if (q == 5)
		sort5(heada, headb);
	else if (q == 4)
		sort4(heada, headb);
	else if (q == 3)
		sort3(heada, headb);
	else if (q == 2)
		sort2(*heada);
	else if (q == 1)
		write(1, "Error !\n", 9);
	else
		radix(heada, headb, q);
}

int	check_sort(t_list *heada)
{
	t_list	*trav;

	if (heada == NULL || heada->next == NULL)
		return (0);
	trav = heada;
	while (trav->next)
	{
		if (*(int *)trav->data > *(int *)trav->next->data)
			return (0);
		trav = trav->next;
	}
	return (1);
}
