# Program name
NAME		= relationship

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
INCLUDES	= -I inc

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

# Source files
SRCS		= $(SRC_DIR)/main.cpp \
			  $(SRC_DIR)/Worker.cpp \
			  $(SRC_DIR)/Position.cpp \
			  $(SRC_DIR)/Statistic.cpp \
			  $(SRC_DIR)/Tool.cpp \
			  $(SRC_DIR)/Shovel.cpp \
			  $(SRC_DIR)/Hammer.cpp \
			  $(SRC_DIR)/Workshop.cpp

# Object files
OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Header files
HEADERS		= $(INC_DIR)/Worker.hpp \
			  $(INC_DIR)/Position.hpp \
			  $(INC_DIR)/Statistic.hpp \
			  $(INC_DIR)/Tool.hpp \
			  $(INC_DIR)/Shovel.hpp \
			  $(INC_DIR)/Hammer.hpp \
			  $(INC_DIR)/Workshop.hpp

# Colors for output
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✓ Object files removed!$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ $(NAME) removed!$(RESET)"

re: fclean all

# Run the program
run: all
	@echo "$(GREEN)Running $(NAME)...$(RESET)"
	@./$(NAME)

# Valgrind check
valgrind: all
	@echo "$(YELLOW)Running valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Show project structure
info:
	@echo "$(YELLOW)Project: $(NAME)$(RESET)"
	@echo "Compiler: $(CXX)"
	@echo "Flags: $(CXXFLAGS)"
	@echo "Sources: $(words $(SRCS)) files"
	@echo "Headers: $(words $(HEADERS)) files"

.PHONY: all clean fclean re run valgrind info
