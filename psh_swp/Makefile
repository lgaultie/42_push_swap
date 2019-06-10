# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 13:20:03 by lgaultie          #+#    #+#              #
#    Updated: 2019/06/10 16:57:47 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = @clang
CFLAGS = -Wall -Werror -Wextra
OBJDIR = obj
SRCDIR = src
LIBDIR = ../libft
SRCS =	main.c				\
		error.c				\
		display.c			\
		selection_sort.c	\
		quicksort.c			\
		operations.c

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
