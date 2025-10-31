NAME = a.out

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp  HumanA.cpp HumanB.cpp Weapon.cpp

HEDEARS = Weapon.hpp  HumanA.hpp HumanB.hpp 

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HEDEARS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all