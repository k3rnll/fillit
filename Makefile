FLAGS = -Wall -Wextra -Werror
SRCS = main.c func.c get_map.c logic.c ft_strnlen.c
OBJ = main.o func.o get_map.o logic.o ft_strnlen.o
LIB_SRCS = ./libft/ft_memalloc.c ./libft/ft_strlen.c ./libft/ft_strequ.c ./libft/ft_strnew.c ./libft/ft_strsub.c ./libft/ft_strcmp.c ./libft/ft_strnequ.c ./libft/ft_strncmp.c
LIB_OBJ = ft_memalloc.o ft_strlen.o ft_strequ.o ft_strnew.o ft_strsub.o ft_strcmp.o ft_strnequ.o ft_strncmp.o
HDRS = fillit.h ./libft/libft.h
NAME = fillit

all: $(NAME)

$(NAME): $(SRCS) $(LIB_SRCS) $(HDRS)
		gcc $(FLAGS) -c $(SRCS) $(LIB_SRCS)
		gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_OBJ)
clean:
		rm -f $(OBJ) $(LIB_OBJ)

fclean:
		rm -f $(OBJ) $(LIB_OBJ) $(NAME)

re:
		make fclean all
