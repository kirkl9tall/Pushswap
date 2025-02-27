/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abismail <abismail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:27:04 by abismail          #+#    #+#             */
/*   Updated: 2025/02/27 14:53:20 by abismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_list(t_list *heada)
{
	t_list	*trav;
	t_list	*next;

	trav = NULL;
	next = NULL;
	next = heada;
	while (next)
	{
		trav = next->next;
		while (trav)
		{
			if (*(int *)next->data == *(int *)trav->data)
			{
				ft_lstclear(&heada);
				exit(write(2, "Error , Duplicated number !", 28));
			}
			trav = trav->next;
		}
		next = next->next;
	}
}

int	indexing(t_list *heada)
{
	t_list	*first;
	t_list	*second;
	int		index;
	int		qts;

	qts = 0;
	first = heada;
	while (first)
	{
		index = 0;
		second = heada;
		while (second)
		{
			if (*(int *)first->data > *(int *)second->data)
				index++;
			second = second->next;
		}
		first->index = index;
		first = first->next;
		qts++;
	}
	return (qts);
}

char	*alloc(int argc, char *argv[])
{
	char	*str;
	int		counter;

	counter = counter_args(argc, argv);
	if (counter == -1)
		exit(write(2, "Error\n", 6));
	str = malloc(counter + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*prepare_str(int argc, char *argv[])
{
	char	*str;

	int (i), (k);
	(i = 1);
	if (argc < 2)
		return (NULL);
	else if (argc >= 2)
	{
		str = alloc(argc, argv);
		while (i < argc)
		{
			k = 0;
			while (argv[i][k] && (argv[i][k] == ' ' || argv[i][k] == '\t'))
				k++;
			if (argv[i][k] == '\0')
				return (free(str), NULL);
			str = ft_strcat(str, argv[i]);
			if (i < argc - 1)
				ft_strcat(str, " ");
			i++;
		}
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	t_list	*heada;
	t_list	*headb;
	char	*str;
	char	**tab;
	int		q;

	str = prepare_str(argc, argv);
	if (str == NULL)
		exit((write(2, "Error\n", 6)));
	tab = ft_split(str, ' ');
	free(str);
	heada = list_create(tab);
	free_tab(tab);
	check_list(heada);
	q = indexing(heada);
	if (!check_sort(heada))
		choice(&heada, &headb, q);
	else
		exit(1);
	ft_lstclear(&heada);
	return (0);
}
