/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:44:08 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/05 16:50:31 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "utils/ft_printf/ft_printf.h"
# include "utils/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				price;
	int				good_nb;
	int				price_a;
	int				price_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_all
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				size_a;
	int				size_b;
}					t_all;

int					parsing(t_all *stack, char **tab);
int					ft_test_nbr(char *tab);
int					checkall(char *tab);
void				print_tab(char **tab);
t_stack				*newstack(int nb);
void				backstack(t_stack **lst, t_stack *new);
t_stack				*laststack(t_stack *lst);
void				add_front(t_stack **lst, t_stack *new);
int					lstsize(t_stack *all);
void				addfront(t_stack **lst, t_stack *new);
long int			ft_atoilong(const char *nptr);
int					ft_error(char *str, t_stack *stack);
void				ft_free_struct(t_stack *stack);
void				ft_free_split(char **tab);
int					sort_nb(t_all *all);
int					check_double(t_stack *stack_a);
int					already_sort(t_all *stack);

void				ft_swap(t_all *all, char c);
void				ft_swap_swap(t_all *all, char c);
void				ft_push(t_all *all, char c);
void				ft_rotate(t_all *all, char c);
void				ft_rotate_rotate(t_all *all, char c);
void				ft_reverse_rotate(t_all *all, char c);

int					ft_medianne(t_all *all);
int					*ft_bbl_sort(t_all *all, int *tab);
int					get_smallest(t_all *all);
int					push_smallest_b(t_all *all, int small);
int					push_smallest_a(t_all *all, int small);
int					algo_3(t_all *all);
int					algo_5(t_all *all);
int					algo_n(t_all *all);
void				cost_calculator(t_all *all);
int					ft_good_nb(t_all *all, int nb);
void				get_price(t_all *all);
int					push_small_price(t_all *all);
void				find_good_nb(t_all *all, int nb);
int					ft_price_a(t_all *all);
int					final_rotate(t_all *all, int small);
void				price_rotate(t_all *all, int pa, int pb);
void				push_small_price_leo(t_all *all);
int					ft_get_parent(int value_tmp_b, t_stack **stack);
void				ft_pr(t_stack **stack);

#endif