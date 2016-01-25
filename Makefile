# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaget <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 14:32:52 by apaget            #+#    #+#              #
#*   Updated: 2016/01/24 15:39:08 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

FLAG = 

NAME = ft_printf.a

SRC = ft_printf.c		\
	  get_opt.c			\
	  get_str_from_num.c\
	  itoabase.c		\
	  make_opt.c		\
	  make_str.c		\
	  make_wstr.c		\
	  wchar_t.c			\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "ft_printf.a created"
	@ranlib $(NAME)
	@echo "ft_printf.a indexed"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "*.o deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "ft_printf.a deleted"

kill:
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all

.PHONY: all, clean, fclean, kill, re
