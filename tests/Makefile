#--------- SO_LONG ---------#

NAME = so_long

#---------- DIR ------------#

SRC_DIR = src
OBJ_DIR = obj
INC_DIR	= include

#---------- SRC ------------#

SRC = main.c

#---------- OBJ ------------#

OBJ = $(SRC:.c=.o)

#--------- LIBFT -----------#

#---------- MLX ------------#

MLX_DIR	= minilibx_linux
MLX		= $(MLX_DIR)/libmlx.a

#------- LIB FLAGS ---------#

#------ COMP & FLAGS -------#

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -g3 -I$(MLX_DIR) -I/user/include/X11
MLX_FLAGS	= -lXext -lX11 -lm -lz

#---------- RULES ----------#

all: $(MLX_DIR) $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) --silent -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re