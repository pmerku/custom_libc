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

DIR		= ft_libft

SOURCES = ft_intlen.c ft_intlen_base.c ft_itoa.c ft_itoa_base.c ft_nsplit.c \
		ft_split.c ft_strempty.c ft_strip_chars.c ft_strjoin.c ft_strtrim.c \
		ft_substr.c get_next_line.c
SOURCES := $(addprefix $(DIR)/,$(SOURCES))

SRC 	+= $(SOURCES)

HEADERS	+= ft_libft.h
