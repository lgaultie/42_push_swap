# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/14 10:37:04 by lgaultie          #+#    #+#              #
#    Updated: 2019/06/18 18:38:06 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @clang
CFLAGS = -Wall -Werror -Wextra
LIBDIR = libft
LIB = $(LIBDIR)/libft.a
CHECKER = $(CHECK_DIR)/checker
PUSH_SWAP = $(PUSH_DIR)/push_swap
CHECK_DIR = chcker
PUSH_DIR = psh_swp
CHECK_OBJDIR = chcker/obj
PUSH_OBJDIR = psh_swp/obj
CHECK_SRCDIR = chcker/src
PUSH_SRCDIR = psh_swp/src
CHECK_SRCS =	main.c				\
				init_stacks.c		\
				error.c				\
				display.c			\
				apply.c				\
				operations.c		\
				check_order.c		\
				read_input.c		\
				free_and_ret.c
PUSH_SRCS =		main.c				\
				init_stack_a.c		\
				error.c				\
				display.c			\
				selection_sort.c	\
				biglist.c			\
				operations.c		\
				free_functions.c	\
				median.c

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(CHECK_OBJ) $(PUSH_OBJ)
	@printf "$(_YELLOW)Compilation... $(_END)"
	@cd $(LIBDIR) && make
	@cd $(CHECK_DIR) && make
	@cd $(PUSH_DIR) && make
	@printf "$(_CYAN)Compilation done [✓]$(_END)\n"

$(CHECK_OBJDIR)/%.o: $(CHECK_SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(PUSH_OBJDIR)/%.o: $(PUSH_SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(CHECK_OBJDIR) :
	@printf "$(_YELLOW)Creating checker_obj folder $(_END)"
	@mkdir $@
	@printf "$(_CYAN)done$(_END)\n"

$(PUSH_OBJDIR) :
	@printf "$(_YELLOW)Creating push_swap_obj folder $(_END)"
	@mkdir $@
	@printf "$(_CYAN)done$(_END)\n"

$(OBJ) : | $(OBJDIR)

checker:
	@cd $(LIBDIR) && make
	@cd $(CHECK_DIR) && make

push_swap:
	@cd $(LIBDIR) && make
	@cd $(PUSH_DIR) && make

clean:
	@printf "$(_YELLOW)clean... $(_END)"
	@cd $(LIBDIR) && make clean
	@rm -rf $(CHECK_OBJDIR)
	@rm -rf $(PUSH_OBJDIR)
	@printf "$(_CYAN)done$(_END)\n"

fclean: clean
	@printf "$(_YELLOW)fclean... $(_END)"
	@rm -f $(LIB)
	@rm -f $(CHECKER)
	@rm -f $(PUSH_SWAP)

	@printf "$(_CYAN)done $(_END)\n"


re: fclean all clean

.PHONY: clean fclean all re
