SRC = ft_atoi.c	ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcmp.c	ft_memmove.c ft_strlcat.c ft_strlen.c	ft_toupper.c \
	ft_bzero.c ft_isalpha.c	ft_isdigit.c ft_memchr.c ft_memcpy.c ft_memset.c ft_strlcpy.c ft_tolower.c ft_memccpy.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	  ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJSRC = $(SRC:%.c=%.o)

OBJBNS = $(BNS:%.c=%.o)

CC = gcc -Wall -Wextra -Werror 

NAME = libft.a 

BONUS = bonus

all: $(NAME)

$(NAME) : $(SRC)
	@$(CC) -c $(SRC) -I.
	@ar rc $(NAME) $(OBJSRC)
	@ranlib $(NAME)

$(BONUS) : $(BNS)
	$(CC) -c $(BNS) -I.
	ar rc $(NAME) $(OBJBNS)
	ranlib $(NAME)

clean : 
	@-rm -f $(OBJSRC) $(OBJBNS)

fclean : clean
	rm  -f $(NAME)

re : fclean all
