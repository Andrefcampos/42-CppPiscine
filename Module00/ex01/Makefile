NAME		= graph

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

INC_DIR		= inc
SRC_DIR		= src
OBJ_DIR		= .obj

SRCS		= $(SRC_DIR)/main.cpp \
			  $(SRC_DIR)/Vector2.cpp \
			  $(SRC_DIR)/Graph.cpp

OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

INCLUDES	= -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "✓ $(NAME) compiled successfully"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "✓ Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "✓ $(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
