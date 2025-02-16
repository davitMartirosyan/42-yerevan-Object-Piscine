NAME = ex01
CXX = c++ -std=c++11
CXX_FLAGS = #-Wall -Wextra -Werror
SRC = main.cpp Graph.cpp Command.cpp CreateCommand.cpp
OBJ = $(SRC:.cpp=.o)
HPP = Graph.hpp

all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXX_FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HPP)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONNY: all re fclean clean
