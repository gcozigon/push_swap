/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:49:51 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/04 20:00:45 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoilong(const char *nptr)
{
	int			i;
	long int	res;
	long		signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + nptr[i] - '0';
		i++;
	}
	return (res * signe);
}

int	ft_test_nbr(char *tab)
{
	int	i;

	i = 0;
	if (tab[i] == '+' || tab[i] == '-')
	{
		if (!(tab[i + 1] >= '0' && tab[i + 1] <= '9'))
			return (ft_printf("Error\nSigne alone\n"), 0);
		i++;
	}
	while (tab[i])
	{
		if (!(tab[i] >= '0' && tab[i] <= '9'))
			return (ft_printf("Error\nWrong ascii\n"), 0);
		i++;
	}
	return (1);
}

int	lstsize(t_stack *all)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = all;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
