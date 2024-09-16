/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:56:14 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/04 15:45:56 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_all *all)
{
	int		small;
	t_stack	*tmp;

	if (!all || !all->stack_a)
		return (0);
	if (lstsize(all->stack_a) == 1)
		return (all->stack_a->nb);
	small = all->stack_a->nb;
	tmp = all->stack_a->next;
	while (tmp)
	{
		if (tmp->nb < small)
			small = tmp->nb;
		tmp = tmp->next;
	}
	return (small);
}

int	push_smallest_b(t_all *all, int small)
{
	t_stack	*tmp;
	int		position;

	position = 0;
	tmp = all->stack_a;
	while (small != tmp->nb && tmp->next)
	{
		position++;
		tmp = tmp->next;
	}
	if (position == 0)
		ft_push(all, 'b');
	else if (position < (lstsize(all->stack_a) / 2))
	{
		while (--position >= 0)
			ft_rotate(all, 'a');
		ft_push(all, 'b');
	}
	else
	{
		while (++position <= lstsize(all->stack_a))
			ft_reverse_rotate(all, 'a');
		ft_push(all, 'b');
	}
	return (0);
}

int	final_rotate(t_all *all, int small)
{
	t_stack	*tmp;
	int		position;

	position = 0;
	tmp = all->stack_a;
	all->size_a = lstsize(all->stack_a);
	while (small != tmp->nb && tmp->next)
	{
		position++;
		tmp = tmp->next;
	}
	if (position == 0)
		return (0);
	else if (position < (all->size_a / 2))
		while (--position >= 0)
			ft_rotate(all, 'a');
	else
		while (++position <= all->size_a)
			ft_reverse_rotate(all, 'a');
	return (0);
}

int	ft_medianne(t_all *all)
{
	t_stack	*tmp;
	int		med;
	int		*array;
	int		i;

	i = 0;
	tmp = all->stack_a;
	all->size_a = lstsize(all->stack_a);
	array = malloc(sizeof(int) * (all->size_a + 1));
	if (!array)
		return (0);
	while (tmp)
	{
		array[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	array = ft_bbl_sort(all, array);
	med = array[(all->size_a - 1) / 3];
	return (free(array), med);
}

int	*ft_bbl_sort(t_all *all, int *array)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < all->size_a)
	{
		j = i + 1;
		while (j < all->size_a)
		{
			if (array[i] > array[j])
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (array);
}
