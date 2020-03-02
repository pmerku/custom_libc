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

DIR		= ft_ctype

SOURCES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c \
		ft_isprint.c ft_isspace.c ft_isupper.c ft_tolower.c ft_toupper.c
SOURCES := $(addprefix $(DIR)/,$(SOURCES))

SRC 	+= $(SOURCES)

HEADERS	+= ft_ctype.h
