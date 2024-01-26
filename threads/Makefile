NAME = phylo
SRC = *.c
OBJ = *.o
CC = gcc -g -pthread -Wall -Wextra -Werror -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	$(MAKE)	clean

$(SRC): 
	$(CC) -c $(SRC)

$(OBJ): $(SRC) 
	$(CC) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all