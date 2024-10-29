NAME = ex00
CPP = c++ -g -fsanitize=address -std=c++98
CPP_FLAGS = -Wall -Wextra -Werror
SRC = main.cpp  Bank.cpp
HPP =  Bank.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HPP)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

push:
	@git add .
	@read -p "Commit: " $commitMessage
	@git commit -m "$commitMessage"
	@git push

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(OBJ)

re: fclean all

.PHONNY: fclean clean all re

