NAME		= find

CXX			= c++
RM			= rm -f

CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS 		=	main.cpp

OBJS 		= $(SRCS:.cpp=.o)

.cpp.o:
			@$(CXX) $(FLAGS) -c $< -o $(<:.cpp=.o)

all :		$(NAME)

$(NAME) :	${OBJS}
			@echo "Building..."
			@${CXX} ${OBJS} $(FLAGS) -o ${NAME}

clean:
			@echo "Cleaning..."
			@rm -f $(OBJS)

fclean:		clean
			@echo "Cleaning all..."
			@rm -f $(NAME)

re: 		fclean all
