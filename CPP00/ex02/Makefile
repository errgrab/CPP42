CPP		= c++
SRCS	= $(wildcard *.cpp)
ODIR	= objs
OBJS	= $(SRCS:%.cpp=$(ODIR)/%.o)
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= bank

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM)r $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

leak: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re
