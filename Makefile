# Paths
SRC_DIR = src
OBJ_DIR = obj

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Source and object files
SRCS        = $(SRC_DIR)/server.c $(SRC_DIR)/client.c $(SRC_DIR)/ft_printf.c
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_SRCS  = $(SRC_DIR)/bonus_server.c $(SRC_DIR)/bonus_client.c $(SRC_DIR)/ft_printf.c
BONUS_OBJS  = $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable names
NAME_1          = server
NAME_2          = client
BONUS_NAME_1    = bonus_server
BONUS_NAME_2    = bonus_client

# Default target
all: $(NAME_1) $(NAME_2)

# Compile objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build executables
$(NAME_1): $(OBJ_DIR)/server.o $(OBJ_DIR)/ft_printf.o
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_2): $(OBJ_DIR)/client.o $(OBJ_DIR)/ft_printf.o
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_NAME_1) $(BONUS_NAME_2)

$(BONUS_NAME_1): $(OBJ_DIR)/bonus_server.o $(OBJ_DIR)/ft_printf.o
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS_NAME_2): $(OBJ_DIR)/bonus_client.o $(OBJ_DIR)/ft_printf.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME_1) $(NAME_2) $(BONUS_NAME_1) $(BONUS_NAME_2)

re: fclean all

.PHONY: all clean fclean re bonus
