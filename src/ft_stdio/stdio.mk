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

DIR		= ft_stdio

SOURCES =
SOURCES := $(addprefix $(DIR)/,$(SOURCES))

SRC 	+= $(SOURCES)

HEADERS	+= ft_stdio.h
