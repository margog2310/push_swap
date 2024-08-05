# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 18:08:20 by mganchev          #+#    #+#              #
#    Updated: 2024/08/05 20:23:45 by mganchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

INCLUDE = ./include
LIBFT = ./libft

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

SRCDIR =./sources
OBJDIR =./build

SRCS = $(SRCDIR)/main.c $(SRCDIR)/instructions/push.c $(SRCDIR)/instructions/swap.c \
$(SRCDIR)/instructions/rotate.c $(SRCDIR)/instructions/reverse_rotate.c $(SRCDIR)/sort/chunk_sort_3.c \
$(SRCDIR)/sort/chunk_sort.c $(SRCDIR)/sort/chunk_split.c $(SRCDIR)/sort/chunk_utils.c $(SRCDIR)/sort/move.c \
$(SRCDIR)/sort/simple_a.c $(SRCDIR)/sort/simple_b.c $(SRCDIR)/sort/utils.c $(SRCDIR)/stack/stack.c \
$(SRCDIR)/stack/sort.c $(SRCDIR)/stack/utils.c $(SRCDIR)/ft_lst.c $(SRCDIR)/utils.c $(SRCDIR)/misc.c \
$(SRCDIR)/check_args.c

OBJS = $(OBJDIR)/main.o $(OBJDIR)/instructions/push.o $(OBJDIR)/instructions/swap.o \
$(OBJDIR)/instructions/rotate.o $(OBJDIR)/instructions/reverse_rotate.o $(OBJDIR)/sort/chunk_sort_3.o \
$(OBJDIR)/sort/chunk_sort.o $(OBJDIR)/sort/chunk_split.o $(OBJDIR)/sort/chunk_utils.o $(OBJDIR)/sort/move.o \
$(OBJDIR)/sort/simple_a.o $(OBJDIR)/sort/simple_b.o $(OBJDIR)/sort/utils.o $(OBJDIR)/stack/stack.o \
$(OBJDIR)/stack/sort.o $(OBJDIR)/stack/utils.o $(OBJDIR)/ft_lst.o $(OBJDIR)/utils.o $(OBJDIR)/misc.o \
$(OBJDIR)/check_args.o

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT)/include -c $< -o $@
	
$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) -L$(LIBFT) $(OBJS) -lft -o $(NAME)

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(OBJDIR)

fclean:
	@make fclean -C $(LIBFT)
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re libft leaks