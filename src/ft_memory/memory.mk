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

MEMORY_DIR		= src/ft_memory

MEMORY_SOURCES 	= ft_bzero.c ft_calloc.c ft_free.c ft_free_array.c ft_malloc.c
MEMORY_SOURCES 	:= $(addprefix $(DIR)/,$(SOURCES))

SRC 	+= $(SOURCES)
HEADERS	+= ft_memory.h
