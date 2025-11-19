NAME = a.out

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp   Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp  WrongCat.cpp


OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp  Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all