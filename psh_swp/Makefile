# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 13:20:03 by lgaultie          #+#    #+#              #
#    Updated: 2019/06/24 17:32:30 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = @clang
CFLAGS = -Wall -Werror -Wextra
OBJDIR = obj
SRCDIR = src
INC = ./includes/
LIBDIR = ../libft
SRCS =	main.c					\
		init_stack_a.c			\
		error.c					\
		selection_sort.c		\
		divide_a.c				\
		sort_b.c				\
		operations.c			\
		free_functions.c		\
		median.c				\
		clean_instructions.c	\
		reverse_sort.c			\
		biglist.c

OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB = $(LIBDIR)/libft.a

_GREEN=\e[32m
_PRPLE=\e[35m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(_YELLOW)Compilation... $(_END)"
	@cd $(LIBDIR) && make
	@$(CC) $(CFLAGS) $(OBJ) -I$(INC) $(LIB) -o $(NAME)
	@printf "$(_GREEN)push_swap done [✓]$(_END)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)/*.h
	@$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(OBJDIR) :
	@printf "$(_YELLOW)Creating $(_PRPLE)push_swap$(_YELLOW) obj folder $(_END)"
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
