SRC = srcs/*.c gnl.a libft.a parse/*.c sprite/*.c

NAME = cube

CC1 = gcc -I /usr/local/include
CC2 = -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit -o  $(NAME)

all : $(NAME)

$(NAME) : $(SRC)
		$(CC1) $(SRC) $(CC2)

clean : 
	rm -rf $(NAME)

re : clean all 
