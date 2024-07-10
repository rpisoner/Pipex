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
BFILES =	
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
	@$(CC) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJS)
	@$(CC) $(BOBJS) -o $(BONUS_NAME)

clean:
	@$(RM) $(OBJS) $(BOBJS)
	@echo "$(R)All .o files removed$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Executable file removed: $(NAME)$(DEF_COLOR)"

re: fclean all

.PHONY: all bonus clean fclean re