##
## EPITECH PROJECT, 2024
## B-CPE-110-RUN-1-1-organized-nathaniel.leperlier
## File description:
## Makefile
##

CC = gcc

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CFLAGS = -g -ggdb -Werror -Wall -Wextra -I ../../include

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
