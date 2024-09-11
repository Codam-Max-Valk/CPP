NAME = iter
CC = clang++
CFLAGS = -std=c++11 -Wall -Wextra -Werror
OBJFOLDER = obj

# Files
SRCS = $(wildcard *.cpp)
OBJS = $(addprefix $(OBJFOLDER)/, $(SRCS:.cpp=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJFOLDER)/%.o: %.cpp
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) $(if $(DEBUG), -DDEBUG=1) -c $< -o $@

debug:
	@$(MAKE) all DEBUG=1

clean:
	rm -rf $(OBJFOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug

