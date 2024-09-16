/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:10:03 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/25 20:24:49 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_all	*all;

	if (ac < 2)
		return (0);
	all = ft_calloc(1, sizeof(t_all));
	if (!all)
		return (0);
	if (parsing(all, av) == 0)
		return (ft_free_struct(all->stack_a), free(all), 0);
	if (already_sort(all) == 0)
		return (ft_free_struct(all->stack_a), free(all), 0);
	sort_nb(all);
	return (ft_free_struct(all->stack_a), ft_free_struct(all->stack_b),
		free(all), 0);
}

int	ft_error(char *str, t_stack *stack)
{
	printf("Error\n-> %s\n", str);
	ft_free_struct(stack);
	exit(1);
}

void	ft_free_struct(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	already_sort(t_all *all)
{
	t_stack	*tmp;

	tmp = all->stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->nb >= tmp->next->nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
