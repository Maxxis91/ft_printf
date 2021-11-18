# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 20:19:54 by gmelissi          #+#    #+#              #
#    Updated: 2021/11/17 20:41:41 by gmelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -include $(HEADS)
PATH_HEAD = ./
HEAD = libft.h
HEADS = $(addprefix $(PATH_HEAD), $(HEAD))
PATH_SRC = ./
SRC = ft_atoi.c ft_bzero.c ft_htoa.c ft_isdigit.c ft_itoa.c ft_mabs.c \
	  ft_memcpy.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcpy.c \
	  ft_strlen.c ft_strncpy.c ft_substr.c ft_toupper.c
SRCS = $(addprefix $(PATH_SRC), $(SRC))
OBJS = $(SRCS:%.c=%.o)
NAME = libft.a

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $?

%.o:		%.c $(HEADS)
		${CC} ${FLAGS} -c $< -o $@

clean: 
		@rm -f $(OBJS)
		@rm -f ./libft.h.gch

fclean: 	clean
		@rm -f $(NAME)

re: fclean all
