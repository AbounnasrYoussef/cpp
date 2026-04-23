NAME    = identify

CC     = c++
CCFLAGS= -Wall -Wextra -Werror -std=c++98

SRC     = main.cpp functions.cpp Base.cpp
OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp  functions.hpp Base.hpp A.hpp B.hpp C.hpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re