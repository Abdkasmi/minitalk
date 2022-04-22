# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 11:38:02 by abkasmi           #+#    #+#              #
#    Updated: 2022/01/10 14:17:30 by abkasmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS1 = server.c \
		minitalk_utils.c

SRCS2 = client.c \
		minitalk_utils.c
	
OBJS1 = $(SRCS1:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

NAME = server

NAME2 = client

all: $(NAME) $(NAME2)

$(NAME) : $(OBJS1)
			gcc -Wall -Werror -Wextra $(SRCS1) -o $(NAME)

$(NAME2): $(OBJS2)
			gcc -Wall -Werror -Wextra $(SRCS2) -o $(NAME2)

clean :
			rm -rf $(OBJS1) $(OBJS2)

fclean : clean
			rm -rf $(NAME) $(NAME2)

re : fclean all

.PHONY : all clean fclean re
