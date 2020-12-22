# **************************************************************************** #
#                                                                              #
#    Project: custom_libc                                 ::::::::             #
#    Members: dvoort, prmerku                           :+:    :+:             #
#    Copyright: 2020                                   +:+                     #
#                                                     +#+                      #
#                                                    +#+                       #
#                                                   #+#    #+#                 #
#    while (!(succeed = try()));                   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Constants
NAME 	= libft.a
TEST 	= test

#Colors
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW 			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN 			= \033[0;36m
END				= \033[0;0m

PREFIX			= $(BLUE)$(NAME) $(END)\xc2\xbb

#Flags and defines
CFLAGS			= -Wall -Wextra -Werror
DFLAGS			= -O3 -g
NASM			= -f

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	NASM += elf64
endif
ifeq ($(UNAME_S),Darwin)
	NASM += macho64
endif

#Sources
SRC_DIR			= src
OUT_DIR			= out
INC_DIR			= include

SRC =
HEADERS =

#Sub-modules
include src/ft_ctype/ctype.mk
include src/ft_errno/errno.mk
include src/ft_libft/libft.mk
include src/ft_llist/llist.mk
include src/ft_math/math.mk
include src/ft_memory/memory.mk
include src/ft_stdio/stdio.mk
include src/ft_stdlib/stdlib.mk
include src/ft_string/string.mk
include src/ft_unistd/unistd.mk

OBJ				= $(patsubst %.c,%.o,$(SRC))
OBJ				:= $(patsubst %.cpp,%.o,$(OBJ))
OBJ				:= $(patsubst %.asm,%.o,$(OBJ))
HEADERS			:= $(addprefix $(INC_DIR)/,$(HEADERS))

#Rules
.PHONY: all clean fclean re bonus run

all: $(NAME)

$(NAME): $(addprefix $(OUT_DIR)/,$(OBJ))
	@echo "$(PREFIX)$(GREEN)Bundling objects...$(END)"
	@ar rcs $@ $^

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@echo "$(PREFIX)$(GREEN)Compiling file $(END)$< $(GREEN)to $(END)$@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DFLAGS) -I./$(INC_DIR) -c -o $@ $<

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@echo "$(PREFIX)$(GREEN)Compiling file $(END)$< $(GREEN)to $(END)$@"
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) $(DFLAGS) -I./$(INC_DIR) -c -o $@ $<

$(OUT_DIR)/%.o: $(SRC_DIR)/%.asm $(HEADERS)
	@echo "$(PREFIX)$(GREEN)Compiling file $(END)$< $(GREEN)to $(END)$@"
	@mkdir -p $(dir $@)
	@nasm $(NASM) -i$(INC_DIR) -o $@ $<

clean:
	@echo "$(PREFIX)$(RED)Removing directory $(END)$(OUT_DIR)"
	@$(RM) -rf $(OUT_DIR)
	@$(MAKE) -C tests clean

fclean: clean
	@echo "$(PREFIX)$(RED)Removing library $(END)$(NAME)"
	@$(RM) -f $(NAME)
	@$(MAKE) -C tests fclean

re:
	@$(MAKE) -f Makefile.mk fclean
	@$(MAKE) -f Makefile.mk all

#Test rules
$(TEST): $(NAME)
	@echo "$(PREFIX)$(GREEN)Bundling tests...$(END)"
	@$(MAKE) -C tests

run: $(TEST)
	./tests/$(TEST)
