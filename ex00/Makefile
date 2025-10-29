NAME			=	myFirstClassInOrthodoxCanonicalForm

CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic

SRCS			=	main.cpp Fixed.cpp

OBJS_PATH		=	objs/
OBJS			=	$(SRCS:%.cpp=objs/%.o)

ISDEBUG = 0

ifeq ($(ISDEBUG), 1)
	CXX +=  -g -fsanitize=address,undefined
endif

ISDEBUG = 0

ifeq ($(ISDEBUG), 1)
	CC = $(DEBUG_CC)
endif

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_PATH)%.o:	%.cpp
	@mkdir -p $(OBJS_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:	$(NAME)

bonus:	$(NAME)

debug:
	make fclean
	$(MAKE) ISDEBUG=1 all

va:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)


clean:
	rm -rf $(OBJS_PATH)

fclean:
	rm -rf $(OBJS_PATH)
	rm -f $(NAME)

re:		fclean all

.PHONY:	all bonus clean fclean re debug va