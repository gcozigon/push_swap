/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:47:08 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/04 19:44:21 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(t_all *all, char **av)
{
	int			x;
	int			y;
	char		**tab;
	long int	tmp;

	y = 0;
	while (av[++y])
	{
		tab = ft_split(av[y], ' ');
		if (!tab)
			return (0);
		x = -1;
		while (tab[++x])
		{
			if (ft_test_nbr(tab[x]) == 0)
				return (ft_free_split(tab), 0);
			tmp = ft_atoilong(tab[x]);
			if (tmp > 2147483648 || tmp < -2147483648)
				return (ft_free_split(tab), ft_printf("Error\n"), 0);
			backstack(&all->stack_a, newstack((int)tmp));
		}
		ft_free_split(tab);
	}
	return (1);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_stack	*newstack(int nb)
{
	t_stack	*x;

	x = malloc(sizeof(t_stack));
	if (!(x))
		return (NULL);
	x->nb = nb;
	x->next = (NULL);
	return (x);
}

void	backstack(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	if (!*lst)
		*lst = new;
	else if (*lst)
	{
		p = laststack(*lst);
		p->next = new;
	}
}

t_stack	*laststack(t_stack *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
