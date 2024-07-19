# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 19:57:56 by rpisoner          #+#    #+#              #
#    Updated: 2024/07/19 17:38:27 by rpisoner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################################################################
#       -MAKEFILE-                                                                      #
#       PROJECT: push_swap                                                              #
#########################################################################################
NAME = pipex
BONUS_NAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

#########################################################################################
# Directories
#########################################################################################
HDR_DIR = .
SRC_DIR = .

#########################################################################################
# Sources & objects
#########################################################################################
FILES = pipex \
		free \
		errors \
		children \
		path_utils \
		libft_utils \
		init_t_pipe \
		libft_utils2 
SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix src/, $(addsuffix .o, $(FILES)))

#########################################################################################
# Bonus sources and objects
#########################################################################################
BFILES = pipex_bonus \
		 free_bonus \
		 errors_bonus \
		 here_doc_bonus \
		 children_bonus \
		 path_utils_bonus \
		 init_t_pipe_bonus \
		 libft_utils_bonus \
		 libft_utils2_bonus \
		 libft_utils3_bonus \
		 get_next_line_bonus 
BSRCS = $(addprefix src_bonus/, $(addsuffix .c, $(BFILES)))
BOBJS = $(addprefix src_bonus/, $(addsuffix .o, $(BFILES)))

#########################################################################################
# Colors
#########################################################################################
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

#########################################################################################
# Rules
#########################################################################################
all: $(NAME)

%.o: %.c
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(G)Linking: $@ $(DEF_COLOR)"
	@$(CC) $(OBJS) -o $(NAME)

bonus: .bonus
.bonus: $(BOBJS)
	@$(CC) $(BOBJS) $(CFLAGS) -o $(NAME)
	@echo "$(G)Linking bonus: $(NAME) $(DEF_COLOR)"
	@touch .bonus

clean:
	@$(RM) $(OBJS) $(BOBJS)
	@$(RM) .bonus
	@echo "$(R)All .o files removed$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Executable file removed: $(NAME)$(DEF_COLOR)"

re: fclean all

.PHONY: all bonus clean fclean re