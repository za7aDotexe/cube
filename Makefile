NAME = cube3D

SRC = parse/elements.c parse/elementscheckerror.c parse/map.c parse/mapcheckerror.c parse/parseutils.c parse/put_error.c parse/read_cube_file.c \
	srcs/hintersection.c srcs/initialize.c srcs/keyshandler.c srcs/main.c srcs/map.c srcs/player.c srcs/projection.c srcs/rays.c srcs/render.c srcs/screenshot.c srcs/update.c srcs/utils.c srcs/utils2.c srcs/vintersection.c \
	sprite/sprite.c sprite/spriteutil.c \
	gnl.a libft.a

CC1 = gcc -Wall -Wextra -Werror -I /usr/local/include
CC2 = -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit -o $(NAME)
all : $(NAME)

$(NAME) : $(SRC)
		$(CC1) $(SRC) $(CC2)

fclean : 
	rm -rf $(NAME)

re : fclean all 
