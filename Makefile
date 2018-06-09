#brew install sdl2

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -I include -I ~/.brew/include

NAME = ft_gkrellm

SRC = main.cpp Computer.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) -L ~/.brew/lib -lSDL2

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all