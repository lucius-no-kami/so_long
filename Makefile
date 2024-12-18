#---------------------------------------------------------------------------#
#																			#
#		███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ 		#
#		██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ 		#
#		███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗		#
#		╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║		#
#		███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝		#
#		╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ 		#
#																			#
#---------------------------------------------------------------------------#

NAME = so_long

SRCDIR = src
OBJDIR = obj
INCDIR = include

# Source Files
SRC = inputs/inputs.c game/init_game.c game/close_game.c so_long.c render/render_sprite.c map/check_valid_path.c map/map_validity.c map/init_map.c player/player_movements.c 
OBJ = $(SRC:.c=.o)
SRC := $(addprefix $(SRCDIR)/, $(SRC))
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJ))

# Libft
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)#/include
# MiniLibx -> Please include in header file: #include "mlx.h"
MINILIBX_DIR := ./minilibx-linux
MLX := $(MINILIBX_DIR)/libmlx.a
# Libraries and Linker Flags
LDFLAGS =  -L$(MINILIBX_DIR) -L$(LIBFT_DIR)
LIBS =  $(MLX) $(LIBFT)

# Archiver
AR = ar
ARFLAGS = rcs

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g3 -I$(MINILIBX_DIR) -I/usr/include/X11 -I$(LIBFT_INCLUDE)

# Detect OS for Flags MiniLibx
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLXFLAGS += -lmlx -lXext -lX11
else ifeq ($(UNAME_S),Darwin)
	MLXFLAGS += -L/opt/X11/lib -lX11 -lXext -lXrandr -lXcursor
endif


# Compilation mode (silent by default, set VERBOSE=1 to show commands)
VERBOSE ?= 0
ifeq ($(VERBOSE),1)
  V := 
else
  V := @
endif

# Colors
RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
RESET   := "\033[0m"



# Default Rule
all: $(OBJDIR) $(MINILIBX_DIR) $(LIBFT) $(NAME)

# Object Directory Rule
$(OBJDIR):
	$(V)mkdir -p $(OBJDIR) || true

# Dependency Files
DEP = $(OBJ:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

# Linking Rule
$(NAME): $(OBJ) $(LIBFT)
	$(V)$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(BONUS_OBJ) $(LIBS) $(MLXFLAGS) -o $(NAME)
	$(V)echo $(GREEN)"[$(NAME)] Executable created ✅"$(RESET)

# Libft
$(LIBFT):
	$(V)$(MAKE) --silent -C $(LIBFT_DIR)
	$(V)echo '[$(NAME)] Libft build successfully'

# MiniLibX
$(MINILIBX_DIR):
	$(V)echo '[$(NAME)] Downloading MiniLibX from github.com...'$(RESET)
	@git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR) > /dev/null 2>&1
	$(V)echo '[$(NAME)] Compiling MiniLibX...'$(RESET)
	@$(MAKE) -C $(MINILIBX_DIR) > /dev/null 2>&1
	$(V)echo '[$(NAME)] MiniLibX installed successfully'$(RESET)

# Clean Rules
clean:
	$(V)echo $(RED)'[$(NAME)] Cleaning objects'd$(RESET)
	$(V)rm -rf $(OBJDIR)

fclean: clean
	$(V)echo $(RED)'[$(NAME)] Cleaning all files'$(RESET)
	$(V)rm -f $(NAME)
	$(V)$(MAKE) --silent -C $(LIBFT_DIR) fclean
	$(V)echo $(RED)'[mlx] Remove directory'$(RESET)
	@rm -rf $(MINILIBX_DIR)

re: fclean all

.PHONY: all clean fclean re bonus regen
.DEFAULT_GOAL := all
