# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mganchev <mganchev@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 18:08:20 by mganchev          #+#    #+#              #
#    Updated: 2024/07/30 18:40:57 by mganchev         ###   ########.fr        #
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
$(SRCDIR)/instructions/rotate.c $(SRCDIR)/instructions/reverse_rotate.c $(SRCDIR)/check_args.c \
$(SRCDIR)/sort.c $(SRCDIR)/utils.c

OBJS = $(OBJDIR)/main.o $(OBJDIR)/instructions/push.o $(OBJDIR)/instructions/swap.o \
$(OBJDIR)/instructions/rotate.o $(OBJDIR)/instructions/reverse_rotate.o $(OBJDIR)/check_args.o \
$(OBJDIR)/sort.o $(OBJDIR)utils.o

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