NAME = cub3D
NAME_BONUS = cub3D_bonus

UNAME = $(shell uname)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

ifeq ($(UNAME), Darwin)
	MINILIBX_PATH = ./mlx_mac
else
	MINILIBX_PATH = ./mlx_linux
endif
ifeq ($(UNAME), Darwin)
	MINILIBX_PATH = ./mlx_mac
else
	MINILIBX_PATH = ./mlx_linux
endif
MINILIBX = $(MINILIBX_PATH)/libmlx.a

CC = cc -g
CCFLAGS = -Wall -Werror -Wextra #-fsanitize=address
RM = rm
RMFLAGS= -f
ifeq ($(UNAME), Darwin) 
	LFLAGS += -framework OpenGL -framework AppKit -L ./mlx_mac -lmlx
else
	LFLAGS += -L ./mlx_linux -lmlx -Ilmlx -lXext -lX11 -lm
endif

GREEN=\033[0;32m
RED=\033[1;31m
YELLOW=\033[1;93m
MAGENTA=\033[0;35m
MAGENTA_BOLD=\033[1;35m
BRANCO_BOLD=\033[1;37m
NC=\033[0m

M_PATH = ./src/mandatory
SRC = $(M_PATH)/main.c \
	$(M_PATH)/init.c \
	$(M_PATH)/clean.c \
	$(M_PATH)/parsing/check.c \
	$(M_PATH)/parsing/check_first.c \
	$(M_PATH)/parsing/utils.c \
	$(M_PATH)/parsing/read_scene_description.c \
	$(M_PATH)/parsing/deal_with_map.c \
	$(M_PATH)/parsing/check_elements.c \
	$(M_PATH)/parsing/check_map_char.c \
	$(M_PATH)/parsing/check_map.c \
	$(M_PATH)/parsing/fill_struct.c \
	$(M_PATH)/move/move.c \
	$(M_PATH)/move/move_aux.c \
	$(M_PATH)/raycasting/raycasting.c \
	$(M_PATH)/raycasting/draw_view.c \
	$(M_PATH)/raycasting/ceiling_and_floor.c \
	$(M_PATH)/raycasting/calculate.c \
	$(M_PATH)/textures/get_textures.c \
	$(M_PATH)/textures/textures.c 

B_PATH = ./src/bonus
SRC_BONUS = $(B_PATH)/main.c \
	$(B_PATH)/main_aux.c \
	$(B_PATH)/clean.c \
	$(B_PATH)/free.c \
	$(B_PATH)/parsing/check.c \
	$(B_PATH)/parsing/check_first.c \
	$(B_PATH)/parsing/utils.c \
	$(B_PATH)/parsing/read_scene_description.c \
	$(B_PATH)/parsing/deal_with_map.c \
	$(B_PATH)/parsing/check_elements.c \
	$(B_PATH)/parsing/check_map_char.c \
	$(B_PATH)/parsing/check_map.c \
	$(B_PATH)/parsing/fill_struct.c \
	$(B_PATH)/move/move.c \
	$(B_PATH)/move/move_aux.c \
	$(B_PATH)/move/colision.c \
	$(B_PATH)/move/handle_interactions.c \
	$(B_PATH)/minimap/minimap.c \
	$(B_PATH)/minimap/minimap_aux.c \
	$(B_PATH)/minimap/draw_beam.c \
	$(B_PATH)/animation/animate.c \
	$(B_PATH)/animation/animate_aux.c \
	$(B_PATH)/animation/update.c \
	$(B_PATH)/raycasting/raycasting.c \
	$(B_PATH)/raycasting/raycasting_aux.c \
	$(B_PATH)/raycasting/draw_view.c \
	$(B_PATH)/raycasting/ceiling_and_floor.c \
	$(B_PATH)/raycasting/calculate.c \
	$(B_PATH)/textures/get_textures.c \
	$(B_PATH)/textures/textures.c \
	$(B_PATH)/raycasting/init_cats.c \
	$(B_PATH)/init/init.c \
	$(B_PATH)/init/init_aux.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR_BONUS = obj_bonus
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR_BONUS)/%.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

	@echo "\n${RED} - ${MAGENTA}Libft compilation is complete ${RED}-${NC}\n"

$(MINILIBX):
	@$(MAKE) -s --no-print-directory -C $(MINILIBX_PATH) 1> /dev/null 2> /dev/null

	@echo "\n${RED} - ${MAGENTA}Minilibx compilation is complete ${RED}-${NC}\n"

$(OBJ_DIR)/%.o: %.c include/cub3d.h
	@mkdir -p $(@D)
	@$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c include/cub3d_bonus.h
	@mkdir -p $(@D)
	@$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX) include/cub3d.h
	@$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LFLAGS)

	@echo "\n${RED} - ${MAGENTA_BOLD}Compilation of all files is complete ${RED}-${NC}\n"

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MINILIBX) include/cub3d.h
	@$(CC) $(CCFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS) $(LFLAGS)

	@echo "\n${RED} - ${MAGENTA_BOLD}Compilation of all files is complete ${RED}-${NC}\n"

clean:
	@$(RM) $(RMFLAGS) $(OBJ) $(LIBFT)
	@$(MAKE) --no-print-directory -C ./libft/ clean
	@$(RM) $(RMFLAGS) -r $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@$(MAKE) --no-print-directory -C $(MINILIBX_PATH) clean 1> /dev/null

	@echo "\n${RED} - ${BRANCO_BOLD}Cleaned all program files ${RED}-${NC}\n"

fclean: clean
	@$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS) $(OBJ) $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@$(MAKE) --no-print-directory -C ./libft/ fclean

	@echo "\n${RED} - ${BRANCO_BOLD}ALL files have been cleaned! ${RED}-${NC}\n"

re: fclean all
	@make -s

.PHONY: all clean fclean re libft minilibx