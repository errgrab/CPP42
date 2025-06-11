CPP		= c++
SRCS	= Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp \
		main.cpp
ODIR	= objs
OBJS	= $(SRCS:%.cpp=$(ODIR)/%.o)
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= test

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM)r $(ODIR)
	$(RM) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
