NAME = ft_malloc
RM = /bin/rm -f

FLAGS = -Wall -Wextra -Werror

# ft_malloc
FILES = ft_malloc
INCLUDE = -I ./includes/
HEADER = ./includes/ft_malloc.h
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/
CFILES = $(patsubst %, $(SRC_DIR)%.c, $(FILES))
OFILES = $(patsubst %, $(OBJ_DIR)%.o, $(FILES))

# libft lib
LFT_DIR = ./libft/
LFT_LIB = $(addprefix $(LFT_DIR), ft.a)
LFT_INC = -I $(LFT_DIR)/include/
LFT_LINK = -L $(LFT_DIR) -l ft

.PHONY: all clean fclean re

all: $(LFT_LIB) $(NAME)

$(LFT_LIB):
	make -C $(LFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo [INFO] ft_malloc Object Files Directory Created

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	gcc $(FLAGS) $(INCLUDE) $(LFT_INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OFILES)
	@gcc $(FLAGS) $(OFILES) $(LFT_LINK) -o $(NAME)
	@echo [INFO] ft_malloc Binary Created

clean:
	@rm -rf $(OBJ_DIR)
	@echo [INFO] ft_malloc Object Files Directory Destroyed
	@make -C $(LFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@echo [INFO] ft_malloc Binary Destroyed
	@make -C $(LFT_DIR) fclean

re: fclean all
