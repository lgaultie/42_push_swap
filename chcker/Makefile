# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 18:26:04 by lgaultie          #+#    #+#              #
#    Updated: 2019/06/14 15:24:34 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = @clang
CFLAGS = -Wall -Werror -Wextra -g3
OBJDIR = obj
SRCDIR = src
INC = ./includes/
LIBDIR = ../libft
SRCS =	main.c				\
		init_stacks.c		\
		error.c				\
		display.c			\
		apply.c				\
		operations.c		\
		check_order.c		\
		read_input.c		\
		free_and_ret.c

OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB = $(LIBDIR)/libft.a

_GREEN=\e[32m
_PURPLE=\e[35m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(_YELLOW)Compilation... $(_END)"
	@cd $(LIBDIR) && make
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -I$(INC) -o $(NAME)
	@printf "$(_GREEN)checker done [✓]$(_END)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(OBJDIR) :
	@printf "$(_YELLOW)Creating $(_PURPLE)checker$(_YELLOW) obj folder $(_END)"
	@mkdir $@
	@printf "$(_CYAN)done$(_END)\n"

$(OBJ) : | $(OBJDIR)
#voir GNU make 4.3 Types of Prerequisites

clean:
	@printf "$(_YELLOW)clean... $(_END)"
	@cd $(LIBDIR) && make clean
	@rm -rf $(OBJDIR)
	@printf "$(_CYAN)done$(_END)\n"

fclean: clean
	@printf "$(_YELLOW)fclean... $(_END)"
	@cd $(LIBDIR) && rm -f $(LIB)
	@rm -rf $(NAME)
	@printf "$(_CYAN)done $(_END)\n"


re: fclean all clean

.PHONY: clean fclean all re
