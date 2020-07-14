##
## EPITECH PROJECT, 2020
## 206neutrinos
## File description:
## makefile
##

SRC	=	src/Main.cpp		\
		src/Exception.cpp		\
		src/reception.cpp		\
		src/parsing.cpp		\
		src/kitchen.cpp		\
		src/cooks.cpp		\
		src/ipc.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	plazza

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) message

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS) -I ./include -pthread -lrt

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ $(NAME) records.txt

re:		fclean all

message:
		@echo "Successfully compiled!"
