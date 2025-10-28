NAME = phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp Contact.cpp main.cpp

HEDEARS =  PhoneBook.hpp Contact.hpp

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
