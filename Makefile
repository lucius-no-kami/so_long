# Nom de l'exécutable
NAME = so_long

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Chemins vers les bibliothèques
MLX_DIR = mlx_linux
LIBFT_DIR = libft
OBJ_DIR = obj

# Fichiers sources et objets
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Bibliothèques à lier
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lm -lX11 -lXext

# Règle par défaut
all: $(NAME)

# Règle pour créer l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJ_DIR)/$^ $(LIBS)

# Règle pour compiler les fichiers .c en fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c -o $(OBJ_DIR)/$@ $<
	$(info CREATED $@)

# Règle pour nettoyer les fichiers objets
clean:
	$(RM) $(OBJ_DIR)/$(OBJS)

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean: clean
	$(RM) $(NAME)

# Règle pour recompiler tout
re: fclean all