# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 12:05:12 by mbotes            #+#    #+#              #
#    Updated: 2019/09/11 14:50:27 by mbotes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH = push_swap
NAME = checker
C_DIR = ./checker_files/
P_DIR = ./push_swap_files/
LIBRARY_NAME = libft.a
LIBRARY_DIR = ./libft/
LIBRARY = $(addprefix $(LIBRARY_DIR), $(LIBRARY_NAME))
FLAGS = -Wall -Werror -Wextra
CHECK_HEAD =	./checker/includes/checker.h
CHECK_FUNC =    srcs/ft_deletelist.c\
				srcs/ft_do_args.c\
				srcs/ft_newstack.c\
				srcs/ft_push.c\
				srcs/ft_print.c\
				srcs/ft_rotate.c\
				srcs/ft_swap.c\
				srcs/ft_error.c\
				srcs/bonus.c\
				srcs/main.c
PUSH_HEAD =		./push_swap/includes/push_swap.h
PUSH_FUNC =     srcs/ft_checker.c\
				srcs/ft_newstack.c\
				srcs/ft_push.c\
				srcs/ft_sort.c\
				srcs/main.c\
				srcs/ft_deletelist.c\
				srcs/ft_rotate.c\
				srcs/ft_swap.c\
				srcs/ft_error.c\
				srcs/utils.c\
				srcs/ft_norm.c
CHECK_FILES = $(addprefix $(C_DIR), $(CHECK_FUNC))
CHECK_OBJ = $(patsubst %.c, %.o, $(CHECK_FILES))
PUSH_FILES = $(addprefix $(P_DIR), $(PUSH_FUNC))
PUSH_OBJ = $(patsubst %.c, %.o, $(PUSH_FILES))
CHECK_OBJECTS = $(CHECK_FILES:.c=.o)
PUSH_OBJECTS = $(PUSH_FILES:.c=.o)
all: $(NAME) $(PUSH)
$(NAME): $(LIBRARY_NAME) $(CHECK_OBJ)
	@gcc $(FLAGS) -o $(NAME) $(CHECK_OBJ) $(LIBRARY) -I $(CHECK_HEAD)
	@echo "Checker Built!"
$(PUSH): $(LIBRARY_NAME) $(PUSH_OBJ)
	@gcc $(FLAGS) -o $(PUSH) $(PUSH_OBJ)  $(LIBRARY) -I $(PUSH_HEAD)
	@echo "Push_Swap Built!"
$(LIBRARY_NAME):
	@make -C $(LIBRARY_DIR)
	@echo "Libft Built!"
%.o: %.c
	gcc -c -o $@ $<
clean:
	@echo "Removing Objects..."
	@/bin/rm -f $(CHECK_OBJ) $(PUSH_OBJ)
	@make clean -C $(LIBRARY_DIR)
	@echo "Clean complete!"
fclean:
	@echo "Removing Objects..."
	@/bin/rm -f $(NAME) $(PUSH)
	@/bin/rm -f $(CHECK_OBJ) $(PUSH_OBJ)
	@make fclean -C $(LIBRARY_DIR)
	@echo "Fclean complete!"
re: fclean all
