CPP		= c++
SRCS	= main.cpp Span.cpp
ODIR	= objs/
OBJS	= $(SRCS:%.cpp=$(ODIR)%.o)
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= test

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^

$(ODIR)%.o: %.cpp
	@mkdir -p $(@D)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
