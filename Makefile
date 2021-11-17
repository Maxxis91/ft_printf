# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 17:30:45 by gmelissi          #+#    #+#              #
#    Updated: 2021/11/17 18:06:23 by gmelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		cc
FLAGS =		-Wall -Wextra -Werror -include $(HEADS)
PATH_HEAD =	./
HEAD =		ftprintf.h
HEADS =		$(addprefix $(PATH_HEAD), $(HEAD))
PATH_SRC =	./
SRC =		ft_parse.c ft_printf.c ft_q_set.c ft_seq.c ft_set_c.c \
			ft_set_d.c ft_set_p.c ft_set_s.c ft_set_u.c ft_set_x.c
SRCS =		$(addprefix $(PATH_SRC), $(SRC))
OBJS =		$(SRCS:%.c=%.o)
NAME =		libftprintf.a

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C ./libft
			cp ./libft/libft.a $(NAME)
			ar rcs $(NAME) $?

%.o:		%.c $(HEADS)
			${CC} ${FLAGS} -c $< -o $@

clean: 
			make clean -C ./libft
			@rm -f $(OBJS)

fclean:		clean
			make fclean -C ./libft
			@rm -f $(NAME)

re:			fclean all
