NAME		= megaphone

CXX			= c++
RM			= rm -f

FLAGS		= -std=c++98 -Wall -Wextra -Werror

SRCS 		= megaphone.cpp

OBJS 		= $(SRCS:.cpp=.o)

.cpp.o:
			@$(CXX) $(FLAGS) -c $< -o $(<:.cpp=.o)

all :		$(NAME)

$(NAME) :	${OBJS}
			@echo "Building megaphone"
			@${CXX} ${OBJS} $(FLAGS) -o ${NAME}

clean:
			@echo "Cleaning..."
			@rm -f $(OBJS)

fclean:		clean
			@echo "Cleaning all..."
			@rm -f $(NAME)

re: 		fclean all
