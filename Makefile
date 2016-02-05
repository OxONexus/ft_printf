# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaget <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 14:32:52 by apaget            #+#    #+#              #
#*   Updated: 2016/01/28 20:02:12 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

FLAG = 

NAME = libftprintf.a

SRC = ft_printf.c		\
	  get_opt.c			\
	  get_str_from_num.c\
	  itoabase.c		\
	  make_opt.c		\
	  make_str.c		\
	  print_wchar.c		\
	  apply_precision_fct.c\
	  make_wstr.c		\
	  apply_fct.c		\
	  unsigned_var.c	\
	  string_tool.c		\
	  wchar_t.c			\
	  libft/ft_atoi.c 			\
	  libft/ft_bzero.c 			\
	  libft/ft_fabs.c				\
	  libft/ft_isblank.c			\
	  libft/ft_strjoinfree.c		\
	  libft/ft_isalnum.c 			\
	  libft/ft_isalpha.c 			\
	  libft/ft_isascii.c 			\
	  libft/ft_isdigit.c 			\
	  libft/ft_isprint.c 			\
	  libft/ft_isspace.c			\
	  libft/ft_itoa.c 			\
	  libft/ft_memalloc.c 		\
	  libft/ft_memccpy.c 			\
	  libft/ft_memchr.c 			\
	  libft/ft_memcmp.c 			\
	  libft/ft_memcpy.c 			\
	  libft/ft_memdel.c 			\
	  libft/ft_memmove.c 			\
	  libft/ft_memset.c 			\
	  libft/ft_putchar.c 			\
	  libft/ft_putchar_fd.c 		\
	  libft/ft_putendl.c 			\
	  libft/ft_putendl_fd.c 		\
	  libft/ft_putnbr.c 			\
	  libft/ft_putnbr_fd.c 		\
	  libft/ft_putstr.c 			\
	  libft/ft_putstr_fd.c 		\
	  libft/ft_strcat.c 			\
	  libft/ft_strchr.c 			\
	  libft/ft_strclr.c 			\
	  libft/ft_strcmp.c 			\
	  libft/ft_strcpy.c 			\
	  libft/ft_strdel.c 			\
	  libft/ft_strdup.c 			\
	  libft/ft_strequ.c 			\
	  libft/ft_striter.c 			\
	  libft/ft_striteri.c 		\
	  libft/ft_strjoin.c 			\
	  libft/ft_strlcat.c 			\
	  libft/ft_strlen.c 			\
	  libft/ft_strmap.c 			\
	  libft/ft_strmapi.c 			\
	  libft/ft_strncat.c 			\
	  libft/ft_strncmp.c 			\
	  libft/ft_strncpy.c 			\
	  libft/ft_strnequ.c 			\
	  libft/ft_strnew.c 			\
	  libft/ft_strnstr.c 			\
	  libft/ft_strrchr.c 			\
	  libft/ft_strsplit.c 		\
	  libft/ft_strstr.c 			\
	  libft/ft_strsub.c 			\
	  libft/ft_strtrim.c 			\
	  libft/ft_swap.c 			\
	  libft/ft_tolower.c 			\
	  libft/ft_toupper.c			\
	  libft/ft_lstnew.c			\
	  libft/ft_lstdelone.c		\
	  libft/ft_lstdel.c			\
	  libft/ft_lstadd.c			\
	  libft/ft_lstiter.c			\
	  libft/ft_lstmap.c			\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "lib created :"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "*.o deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "ft_printf.a deleted"

test1:
	gcc apply_fct.c ft_printf.c get_opt.c get_str_from_num.c itoabase.c make_opt.c make_str.c make_wstr.c string_tool.c wchar_t.c unsigned_var.c test.c -I. libft/libft.a
	./a.out > ft_printf
	mgdiff ft_printf printf
	rm a.out

test2:
	gcc apply_fct.c ft_printf.c get_opt.c get_str_from_num.c itoabase.c make_opt.c make_str.c make_wstr.c string_tool.c wchar_t.c unsigned_var.c main.c -I. libft/libft.a
	./a.out

debug:
	gcc ft_printf.c get_opt.c get_str_from_num.c itoabase.c make_opt.c make_str.c make_wstr.c test.c wchar_t.c libft/libft.a -g
	gdb a.out
	rm a.out

kill:
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all

.PHONY: all, clean, fclean, kill, re
