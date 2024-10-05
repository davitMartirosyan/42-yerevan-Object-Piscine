NAME = ex00
CPP = c++ -std=c++98
CPP_FLAGS = -Wall -Wextra -Werror
SRC = main.cpp Account.cpp Bank.cpp
HPP = Account.hpp Bank.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HPP)
	$(CPP) $(CPP_FLAGS) -c $< -o $@


fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(OBJ)

re: fclean all

.PHONNY: fclean clean all re

