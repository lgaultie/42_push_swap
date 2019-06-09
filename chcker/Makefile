# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 18:26:04 by lgaultie          #+#    #+#              #
#    Updated: 2019/06/09 18:27:01 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = @clang
CFLAGS = -Wall -Werror -Wextra -g
OBJDIR = obj
SRCDIR = src
LIBDIR = ../libft
SRCS =	main.c				\
		argv_error.c		\
		display.c			\
		apply.c				\
		operations.c		\
		check_order.c		\
		read_input.c		\
		free_and_ret.c

OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB = $(LIBDIR)/libft.a

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(_YELLOW)Compilation... $(_END)"
	@cd $(LIBDIR) && make
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@printf "$(_GREEN)Compilation done [✓]$(_END)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@printf "$(_YELLOW)Creating obj folder $(_END)"
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
