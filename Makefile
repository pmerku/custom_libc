# **************************************************************************** #
#                                                                              #
#    Makefile                                             ::::::::             #
#    prmerku                                            :+:    :+:             #
#    prmerku@student.codam.nl                          +:+                     #
#                                                     +#+                      #
#                                                    +#+                       #
#    while (!(succeed = try()))                    #+#    #+#                  #
#    Project: github_libc                          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Constants
NAME = libft.a
TEST = test

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
DFLAGS			= -O3
NASM			= -f

ifeq ($(OS),Windows_NT)
	NASM += win64
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		NASM += elf64
	endif
	ifeq ($(UNAME_S),Darwin)
		NASM += macho64
	endif
endif

#Sources
SRC_DIR			= src
OUT_DIR			= out
INC_DIR			= include

SRC =
HEADERS =

#Sub-modules
include	src/ft_ctype/ctype.mk
include	src/ft_dllist/dllist.mk
include	src/ft_libft/libft.mk
include	src/ft_llist/llist.mk
include	src/ft_math/math.mk
include	src/ft_memory/memory.mk
include	src/ft_stdio/stdio.mk
include	src/ft_stdlib/stdlib.mk
include	src/ft_string/string.mk
include	src/ft_unistd/unistd.mk

OBJ				= $(patsubst %.c,%.o,$(SRC))
OBJ				:= $(patsubst %.s,%.o,$(OBJ))

HEADERS			:= $(addprefix $(INC_DIR)/,$(HEADERS))

ifdef WITH_BONUS
OBJ_FILES		= $(OBJ) $(BONUS_OBJ)
else
OBJ_FILES		= $(OBJ)
endif

#Test sources
TESTS_DIR		= tests
SRC_TESTS		= tests/main.c

#Rules
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(addprefix $(OUT_DIR)/,$(OBJ))
	@echo "$(PREFIX)$(GREEN)Bundling objects...$(END)"
	@ar rcs $(NAME) $(addprefix $(OUT_DIR)/,$(OBJ))

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@echo "$(PREFIX)$(GREEN)Compiling file $(END)$< $(YELLOW)to $(END)$@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DFLAGS) -I$(INC_DIR) -c -o $@ $<

$(OUT_DIR)/%.o: $(SRC_DIR)/%.s $(HEADERS)
	@echo "$(PREFIX)$(GREEN)Compiling file $(END)$< $(YELLOW)to $(END)$@"
	@mkdir -p $(dir $@)
	@nasm $(NASM) -o $@ $<

clean:
	@echo "$(PREFIX)$(RED)Removing directory $(END)$(OUT_DIR)"
	@$(RM) -rf $(OUT_DIR)

fclean: clean
	@echo "$(PREFIX)$(RED)Removing file $(END)$(NAME)"
	@$(RM) -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

bonus:
	@$(MAKE) WITH_BONUS=1 all

#Test rules
test:
	@echo "$(PREFIX)$(GREEN)Bundling tests...$(END)"
	@$(CC) $(CFLAGS) -o $(TEST) -Iinclude $(SRC_TESTS) libft.a

test_clean:
	@echo "$(PREFIX)$(RED)Removing tests...$(END)$(NAME)"
	@$(RM) -f *.o
	@$(RM) -f $(TEST)
