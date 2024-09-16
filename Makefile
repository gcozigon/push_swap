LIBFT			=	utils/libft/libft.a

PRINTF			=	utils/ft_printf/libftprintf.a

SRCS			=	main.c parsing.c utils.c sort_nb.c moove.c algo.c algo_utils.c algo_utils1.c algo_utils2.c \

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -g3 -Wall -Wextra -Werror

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
					@make -C utils/libft
					@make -C utils/ft_printf
					cc $(OBJS) -o $(NAME)-L. ${LIBFT} ${PRINTF} -o $(NAME)

clean:
					make clean -C utils/libft/
					make clean -C utils/ft_printf/
						$(RM) $(OBJS)

fclean:			clean
					make fclean -C utils/libft/
					make fclean -C utils/ft_printf/
						$(RM) $(NAME)

re:						fclean $(NAME)

.PHONY:			all clean fclean re
