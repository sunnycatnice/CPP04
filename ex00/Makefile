# Nome dell'eseguibile
NAME = polymorphism

# Compilatore e flag
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# File sorgente e oggetti
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)

# Regola principale
all: $(NAME)

# Compilazione dell'eseguibile
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compilazione dei file oggetto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pulizia dei file oggetto
clean:
	rm -f $(OBJS)

# Pulizia completa (oggetti + eseguibile)
fclean: clean
	rm -f $(NAME)

# Ricompilazione completa
re: fclean all

.PHONY: all clean fclean re

