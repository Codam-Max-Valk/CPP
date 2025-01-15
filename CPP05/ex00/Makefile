NAME = bureau
CC = clang++
CFLAGS = -std=c++11 -Wall -Wextra -Werror
OBJFOLDER = obj

# Files
SRCS = $(wildcard *.cpp)
OBJS = $(addprefix $(OBJFOLDER)/, $(SRCS:.cpp=.o))

# Rules
all: $(NAME)

run: all clean
	./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJFOLDER)/%.o: %.cpp
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJFOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

