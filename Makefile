##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CC = gcc

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = bonus

GLFWFLAGS = -lGLEW -lglfw

COMFLAGS = -Werror -Wall -Wextra

GLADFLAGS = -L ./lib/glad -lglad

LIBMYFLAGS = -L ./lib/my -lmy

OPTIONAL = $(GLADFLAGS) $(LIBMYFLAGS)

MANDATORY = $(COMFLAGS) $(GLFWFLAGS) -I ./include

CFLAGS = $(MANDATORY) $(OPTIONAL)

all: complib $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
complib:
	cd lib/glad && make
	cd lib/my && make
clean:
	rm -rf $(OBJ)
cleanlib:
	cd lib/glad && make clean
	cd lib/my && make clean
fclean: fcleanlib clean
	rm -rf $(NAME)
fcleanlib:
	cd lib/glad && make fclean
	cd lib/my && make fclean
re: fclean all
