NAME = a.out

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
