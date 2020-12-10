NAME = cub3D

libft = libft/libft.a

SRC = parse/floor_ciel.c parse/resolution.c parse/textures.c parse/elementscheckerror.c parse/map.c parse/mapcheckerror.c parse/parseutils.c parse/put_error.c parse/read_cube_file.c \
	srcs/hintersection.c srcs/initialize.c srcs/keyshandler.c srcs/main.c srcs/map.c srcs/player.c srcs/projection.c srcs/rays.c srcs/render.c srcs/screenshot.c srcs/update.c srcs/utils.c srcs/utils2.c srcs/vintersection.c \
	sprite/sprite.c sprite/spriteutil.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c \
	$(libft) 
CC1 = gcc -Wall -Wextra -Werror -I /usr/local/include
CC2 = -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all : $(NAME)

$(libft) :
	@make -C libft/
	@make clean -C libft/

$(NAME) : $(libft) $(SRC)
		@$(CC1) $(SRC) $(CC2)

clean :
	@rm -rf screenshot.bmp

fclean : clean
	@rm -rf $(NAME)

re : fclean all
	@make re -C libft/