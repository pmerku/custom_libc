# **************************************************************************** #
#                                                                              #
#    Project: minishell                                   ::::::::             #
#    Members: dvoort, prmerku                           :+:    :+:             #
#    Copyright: 2020                                   +:+                     #
#                                                     +#+                      #
#                                                    +#+                       #
#                                                   #+#    #+#                 #
#    while (!(succeed = try()));                   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Constants
NAME			= test

# Compiler
CFLAGS			= -Wall -Werror -Wextra -std=c++11
DFLAGS			= -g

# Files
SRC_DIR			= .
OUT_DIR			= out
INC_DIR			= .
SRC				= main.cpp
HEADERS			= tester.h

INC_LIBFT		= ../include

# Sub-modules
include ft_ctype/ctype.mk
include ft_libft/libft.mk
include ft_unistd/unistd.mk
include	mutantstack/mutantstack.mk

# Fix sources and headers
OBJ				= $(patsubst %.cpp,%.o,$(SRC))
HEADERS			:= $(addprefix $(INC_DIR)/,$(HEADERS))

# Colours
DARK_GREEN		= \033[0;32m
GREEN			= \033[0;92m
END				= \033[0;0m

PREFIX			= $(DARK_GREEN)$(NAME) $(END)\xc2\xbb

all: $(NAME)

deps:
	@echo "$(SRC)"

$(NAME): $(addprefix $(OUT_DIR)/,$(OBJ))
	@echo "$(PREFIX)$(GREEN) Bundling objects...$(END)"
	@$(CXX) $(CFLAGS) $(DFLAGS) -I$(INC_DIR) -I$(INC_LIBFT) -o $@ $(addprefix $(OUT_DIR)/,$(OBJ)) -L.. -lft

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@echo "$(PREFIX)$(GREEN) Compiling file $(END)$< $(GREEN)to $(END)$@"
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) $(DFLAGS) -I$(INC_DIR) -I$(INC_LIBFT) -o $@ -c $<

clean:
	@echo "$(PREFIX)$(GREEN) Removing directory $(END)$(OUT_DIR)"
	@rm -rf $(OUT_DIR)

fclean: clean
	@echo "$(PREFIX)$(GREEN) Removing file $(END)$(NAME)"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

exec: $(NAME)
	./$(NAME)

valgrind: $(NAME)
	valgrind --undef-value-errors=no --leak-check=full ./$(NAME)

.PHONY: all clean fclean re exec valgrind