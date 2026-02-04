# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: [your login] <[your email]>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: YYYY/MM/DD HH:MM:SS by [login]          #+#    #+#              #
#    Updated: YYYY/MM/DD HH:MM:SS by [login]         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= program_name

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Source files
SRCS		= main.cpp \
			  ClassName.cpp

# Object files
OBJS		= $(SRCS:.cpp=.o)

# Header files
HEADERS		= ClassName.hpp

# Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully$(RESET)"

%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)🗑️  Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
