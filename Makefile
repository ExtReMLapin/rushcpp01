#brew install sdl2 && brew install sdl2_ttf

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -I include -I ~/.brew/include -g

NAME = ft_gkrellm

SRC = main.cpp Computer.cpp modules/IMonitorModule.cpp modules/IMonitorDisplay.cpp modules/CPUModule.cpp modules/SDLRenderer.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) -L ~/.brew/lib -lSDL2 -lSDL2_ttf -lSDL2_image 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all