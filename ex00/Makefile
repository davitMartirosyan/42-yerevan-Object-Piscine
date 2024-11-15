NAME = ex00
CPP = c++ -g  -std=c++98
CPP_FLAGS = -Wall -Wextra -Werror
SRC = $(wildcard src/*.cpp) main.cpp
HPP =  $(wildcard inc/*.hpp)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HPP)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

push:
	@read -p "Commit message: " msg; \
	git add .; \
	git commit -m "$$msg"; \
	git push

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(OBJ)

re: fclean all

.PHONNY: fclean clean all re
