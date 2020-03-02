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

DIR		= ft_llist

SOURCES = ft_llist_clear.c ft_llist_free.c ft_llist_iter.c ft_llist_new.c \
		ft_llist_push_back.c ft_llist_push_front.c ft_llist_size.c
SOURCES := $(addprefix $(DIR)/,$(SOURCES))

SRC 	+= $(SOURCES)

HEADERS	+= ft_llist.h
