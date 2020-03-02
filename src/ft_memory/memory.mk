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

DIR		= ft_memory

SOURCES = ft_bzero.c ft_calloc.c ft_free.c ft_free_array.c ft_malloc.c
SOURCES := $(addprefix $(DIR)/,$(SOURCES))

SRC 	+= $(SOURCES)

HEADERS	+= ft_memory.h
