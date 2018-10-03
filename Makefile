NAME = ft_malloc
RM = /bin/rm -f

FLAGS = -Wall -Wextra -Werror

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

# ft_malloc
FILES = ft_malloc malloc realloc show_alloc_mem free
INCLUDE = -I ./includes/
HEADER = ./includes/ft_malloc.h
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/
CFILES = $(patsubst %, $(SRC_DIR)%.c, $(FILES))
OFILES = $(patsubst %, $(OBJ_DIR)%.o, $(FILES))
SYM_LINK = libft_malloc_$(HOSTTYPE).so
SYM_FILE = libft_malloc.so

# libft lib
LFT_DIR = ./libft/
LFT_LIB = $(addprefix $(LFT_DIR), ft.a)
LFT_INC = -I $(LFT_DIR)/include/
LFT_LINK = -L $(LFT_DIR) -l ft

.PHONY: all clean fclean re

all: rmsymlink $(LFT_LIB) $(NAME)
	@ln -s $(SYM_LINK) $(SYM_FILE)
	@echo $(SYM_FILE) created

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

rmsymlink:
	rm -f $(SYM_FILE)

clean:
	@rm -rf $(OBJ_DIR)
	@echo [INFO] ft_malloc Object Files Directory Destroyed
	@make -C $(LFT_DIR) clean
	@rm -f $(SYM_FILE)
	@echo $(SYM_FILE) removed

fclean: clean
	@$(RM) $(NAME)
	@echo [INFO] ft_malloc Binary Destroyed
	@make -C $(LFT_DIR) fclean

re: fclean all