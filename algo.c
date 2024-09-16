/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:51:41 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/04 15:40:25 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo_3(t_all *all)
{
	t_stack	*tmp;

	tmp = all->stack_a;
	if (tmp->nb < tmp->next->nb && tmp->next->nb > tmp->next->next->nb
		&& tmp->nb < tmp->next->next->nb)
	{
		ft_reverse_rotate(all, 'a');
		ft_swap(all, 'a');
	}
	else if (tmp->nb > tmp->next->nb && tmp->next->nb > tmp->next->next->nb
		&& tmp->nb > tmp->next->next->nb)
	{
		ft_swap(all, 'a');
		ft_reverse_rotate(all, 'a');
	}
	else if (tmp->nb > tmp->next->nb && tmp->next->nb < tmp->next->next->nb
		&& tmp->nb > tmp->next->next->nb)
		ft_rotate(all, 'a');
	else if (tmp->nb > tmp->next->nb && tmp->next->nb < tmp->next->next->nb
		&& tmp->nb < tmp->next->next->nb)
		ft_swap(all, 'a');
	else if (tmp->nb < tmp->next->nb && tmp->next->nb > tmp->next->next->nb
		&& tmp->nb > tmp->next->next->nb)
		ft_reverse_rotate(all, 'a');
	return (1);
}

int	algo_5(t_all *all)
{
	int	first;
	int	second;

	first = get_smallest(all);
	push_smallest_b(all, first);
	if (all->size_a == 5)
	{
		second = get_smallest(all);
		push_smallest_b(all, second);
	}
	algo_3(all);
	ft_push(all, 'a');
	ft_push(all, 'a');
	return (1);
}

int	algo_n(t_all *all)
{
	int	i;
	int	med;

	i = 0;
	while (lstsize(all->stack_a) > 3)
	{
		all->size_a = lstsize(all->stack_a);
		med = ft_medianne(all);
		if (all->stack_a->nb < med)
			ft_push(all, 'b');
		else
			ft_rotate(all, 'a');
	}
	algo_3(all);
	while (lstsize(all->stack_b))
	{
		cost_calculator(all);
		get_price(all);
		push_small_price_leo(all);
	}
	ft_push(all, 'a');
	i = get_smallest(all);
	final_rotate(all, i);
	return (0);
}

int	ft_get_parent(int value_tmp_b, t_stack **stack)
{
	t_stack	*tmp;
	int		result;

	tmp = *stack;
	result = 2147483647;
	while (tmp)
	{
		if (value_tmp_b < tmp->nb && result > tmp->nb)
			result = tmp->nb;
		tmp = tmp->next;
	}
	return (result);
}

void	ft_pr(t_stack **stack)
{
	int		p_a;
	int		p_b;
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->price_a > 0)
		p_a = tmp->price_a;
	else
		p_a = tmp->price_a * -1;
	if (tmp->price_b > 0)
		p_b = tmp->price_b;
	else
		p_b = tmp->price_b * -1;
	tmp->price = p_a + p_b;
}
