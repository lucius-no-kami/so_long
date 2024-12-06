#--------- SO_LONG ---------#

NAME = so_long

#---------- DIR ------------#

SRC_DIR = src
OBJ_DIR = obj
INC_DIR	= include

#---------- SRC ------------#

SRC =	so_long.c map/init_map.c map/map_validity.c game/init_game.c game/close_game.c inputs/inputs.c \
		render/render_sprite.c   player/player_movements.c

#---------- OBJ ------------#

OBJ = $(SRC:.c=.o)
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ := $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(OBJ)) # Permet de remplacer le src/ devant l'objet par obj/ (src/ se met car il transforme les fichiers sources src/name.c en src/name.o)

#--------- LIBFT -----------#

LIBFT_DIR 	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

#---------- MLX ------------#

MLX_DIR	= minilibx_linux
MLX		= $(MLX_DIR)/libmlx.a

#------- LIB FLAGS ---------#

LBFLAGS	= -L$(MLX_DIR) -L$(LIBFT_DIR)
LIBS	= $(MLX) $(LIBFT)

#------ COMP & FLAGS -------#

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -g3 -I$(MLX_DIR) -I/user/include/X11 -I$(LIBFT_DIR)
MLX_FLAGS	= -lXext -lX11 -lm -lz

#---------- RULES ----------#

all: $(MLX_DIR) $(LIBFT_DIR) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LBFLAGS) $(OBJ) $(LIBS) $(MLX_FLAGS) -o $(NAME)

# Permet de creer le repertoire pour les obj
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) --silent -C $(LIBFT_DIR)
	$(info CREATED $(LIBFT))

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) --silent -C $(LIBFT_DIR) fclean
	@$(MAKE) --silent -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re