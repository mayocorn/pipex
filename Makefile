# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 13:59:07 by mayocorn          #+#    #+#              #
#    Updated: 2022/07/19 05:11:20 by mayocorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex

SRCDIR  = ./src/
SRCS    = main.c \
          child_process/process_child_1.c \
          child_process/process_child_2.c \
          utils/find_cmd_fullpath.c \
          utils/ft_exit.c \
          utils/print_usage.c \
          utils/search_path.c \
          wrapper/wrapper_dup2.c \
          wrapper/wrapper_execve.c \
          wrapper/wrapper_fork.c \
          wrapper/wrapper_open.c \
          wrapper/wrapper_pipe.c \
          wrapper/wrapper_split.c \
          wrapper/wrapper_strdup.c \
          wrapper/wrapper_strjoin.c


OBJDIR  = ./obj/
OBJS    = $(addprefix $(OBJDIR), $(SRCS:%.c=%.o))

DEPS    = $(OBJS:%.o=%.d)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
INCLUDE = ./include/

LIBFT = libft.a

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -I$(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

-include $(DEPS)

.PHONY: all
all: $(NAME)

# .PHONY: bonus
# bonus: $(B_NAME)

.PHONY: clean
clean: 
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

.PHONY: re
re: fclean all
