/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abismail <abismail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:26:56 by abismail          #+#    #+#             */
/*   Updated: 2025/02/26 22:26:57 by abismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	atoi_check(char nptr, int signe, int num)
{
	if (signe == 1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && (nptr
					- '0') > INT_MAX % 10)))
		exit(write(2, "error: number exceeds INT_MAX\n", 31));
	else if (signe == -1 && (num > (long)INT_MAX / 10 || (num == (long)INT_MAX
				/ 10 && (nptr - '0') > ((long)INT_MAX % 10 + 1))))
		exit(write(2, "error: number is less than INT_MIN\n", 36));
}

int	ft_atoi(const char *nptr)
{
	int	x;
	int	signe;
	int	num;

	x = 0;
	signe = 1;
	num = 0;
	while (nptr[x] == '\t' || nptr[x] == ' ' || (nptr[x] >= 9 && nptr[x] <= 13))
		x++;
	if (nptr[x] == '+' || nptr[x] == '-')
		if (nptr[x++] == '-')
			signe *= -1;
	if (!nptr[x])
		exit(write(2, "error in the number !\n", 23));
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		atoi_check(nptr[x], signe, num);
		num = num * 10 + (nptr[x++] - '0');
	}
	if (nptr[x] != '\0' && (!(nptr[x] >= '1' && nptr[x] <= '9')))
		exit(write(2, "error in the number !\n", 23));
	return (num * signe);
}

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	sd;
	size_t	y;

	sd = 0;
	y = 0;
	while (dest[sd])
		sd++;
	while (src[y])
	{
		dest[sd + y] = src[y];
		y++;
	}
	dest[sd + y] = '\0';
	return (dest);
}

int	counter_args(int argc, char *argv[])
{
	int	counter;
	int	i;
	int	j;

	i = 1;
	counter = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			counter++;
			j++;
		}
		if (i < argc - 1)
			counter++;
		i++;
	}
	return (counter);
}
