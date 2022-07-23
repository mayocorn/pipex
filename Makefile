# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 13:59:07 by mayocorn          #+#    #+#              #
#    Updated: 2022/07/24 03:16:23 by mayocorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex

SRCDIR  = ./src/
SRCS    = main.c \
          child_process/process_first_child.c \
          child_process/process_last_child.c \
          utils/find_cmd_fullpath.c \
          utils/ft_exit.c \
          utils/search_path.c \
          utils/wait_child_process.c \
          wrapper/wrapper_dup2.c \
          wrapper/wrapper_execve.c \
          wrapper/wrapper_fork.c \
          wrapper/wrapper_open.c \
          wrapper/wrapper_pipe.c \
          wrapper/wrapper_split.c \
          wrapper/wrapper_strdup.c \
          wrapper/wrapper_strjoin.c

BSRCS   = main_bonus.c \
          child_process/process_first_child.c \
          child_process/process_first_child_heredoc.c \
          child_process/process_middle_child.c \
          child_process/process_last_child.c \
          get_next_line/get_next_line.c \
          get_next_line/get_next_line_utils.c \
          utils/find_cmd_fullpath.c \
          utils/ft_exit.c \
		  utils/read_heredoc.c \
          utils/search_path.c \
          utils/swap_pipe.c \
          utils/wait_child_process.c \
          wrapper/wrapper_calloc.c \
          wrapper/wrapper_dup2.c \
          wrapper/wrapper_execve.c \
          wrapper/wrapper_fork.c \
          wrapper/wrapper_open.c \
          wrapper/wrapper_pipe.c \
          wrapper/wrapper_split.c \
          wrapper/wrapper_strdup.c \
          wrapper/wrapper_strjoin.c

ifeq ($(MAKECMDGOALS), bonus)
	SRCS = $(BSRCS)
endif

OBJDIR  = ./obj/
OBJS    = $(addprefix $(OBJDIR), $(SRCS:%.c=%.o))
DEPS    = $(OBJS:%.o=%.d)

LIBFT = libft.a

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
INCLUDE = ./include/

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -I$(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

$(LIBFT): dummy
	$(MAKE) -C libft

-include $(DEPS)

.PHONY: all
all: $(NAME)

.PHONY: bonus
bonus: $(NAME)

.PHONY: clean
clean: 
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: dummy
dummy:
