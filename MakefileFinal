ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

MALLOC = libft_malloc_${HOSTTYPE}.so
CC = gcc
OBJ_DIR = ./objs/
OBJFLAGS = -g -Wall -Werror -Wextra -c -fPIC
LIBFLAGS = -g -shared -ldl
SOURCE_DIR = srcs
MALLOC_SRC = free ft_malloc malloc realloc show_alloc_mem

MALLOC_OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(MALLOC_SRC))
MALLOC_INC = -I includes

# libft lib
LFT_DIR = ./libft/
LFT_LIB = $(addprefix $(LFT_DIR), ft.a)
LFT_INC = -I $(LFT_DIR)/include/
LFT_LINK = -L $(LFT_DIR) -l ft

all: $(MALLOC)

$(MALLOC): $(LFT_LIB) $(MALLOC_OBJ)
	@printf "%-50s" "Building $@... "
	@$(CC) $(LIBFLAGS) $(MALLOC_OBJ) $(LFT_LINK) -o $@
	@rm -f libft_malloc.so
	@ln -s $@ libft_malloc.so
	@echo "DONE"

$(LFT_LIB):
	@printf "%-50s" "Building $@... "
	make -C $(LFT_DIR)
	@echo "DONE"

$(OBJ_DIR)%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo " > Compiling $<..."
	@$(CC) $(OBJFLAGS) $(MALLOC_INC) $(LFT_INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LFT_DIR) clean
	@echo "Object files removed"

fclean: clean
	@make -C $(LFT_DIR) fclean
	@rm -f $(MALLOC)
	@rm -f libft_malloc.so
	@echo "$(MALLOC) removed"

re: fclean all
