NAME = bureaucrat

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp  Bureaucrat.hpp
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

