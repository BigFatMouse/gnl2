NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:%.c=%.o) 
CC = gcc
FLAGS = -Wall -Wextra -Werror
OPTION = -D BUFFER_SIZE=32

all: $(NAME)
	
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c 
	$(CC) $(FLAGS) $(OPTION) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all