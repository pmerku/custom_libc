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
DFLAGS			= -03
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

SRC				= \
				ft_string/ft_strlen.s \
				ft_string/ft_memset.c \
				ft_string/ft_memccpy.c \
				ft_string/ft_memcpy.c \
				ft_string/ft_memchr.c \
				ft_string/ft_memcpm.c \
				ft_string/ft_memmove.c

SRC				+= \
				ft_memory/ft_bzero.c \
				ft_memory/ft_calloc.c \
				ft_memory/ft_malloc.c \
				ft_memory/ft_free.c \
				ft_memory/ft_free_array.c

SRC				+= \
				ft_ctype/ft_isdigit.c \
				ft_ctype/ft_isspace.c \
				ft_ctype/ft_isprint.c \
				ft_ctype/ft_isascii.c \
				ft_ctype/ft_isalnum.c \
				ft_ctype/ft_isprint.c \
				ft_ctype/ft_isupper.c \
				ft_ctype/ft_islower.c \
				ft_ctype/ft_tolower.c \
				ft_ctype/ft_toupper.c

SRC				+= \
				ft_libft/ft_intlen.c \
				ft_libft/ft_itoa.c \
				ft_libft/ft_intlen_base.c \
				ft_libft/ft_itoa_base.c \
				ft_libft/ft_split.c

SRC				+= \
				ft_unistd/ft_read.s \
				ft_unistd/ft_write.s \
				ft_unistd/ft_putchar_fd.c \
				ft_unistd/ft_putstr_fd.c \
				ft_unistd/ft_putendl_fd.c \
				ft_unistd/ft_putnbr_fd.c

OBJ				= $(patsubst %.c,%.o,$(SRC))
OBJ				:= $(patsubst %.s,%.o,$(OBJ))

HEADERS			= ft_string.h ft_memory.h ft_ctype.h ft_libft.h ft_stdlib.h \
				ft_unistd.h
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
