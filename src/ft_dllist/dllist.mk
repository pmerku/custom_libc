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

DLLIST_DIR		= ft_dllist

DLLIST_SOURCES	= ft_dllist_clear.c ft_dllist_free.c ft_dllist_iter.c ft_dllist_new.c \
	ft_dllist_push_back.c ft_dllist_push_front.c ft_dllist_rclear.c ft_dllist_rfree.c \
	ft_dllist_riter.c ft_dllist_rsize.c ft_dllist_size.c ft_dllist_last.c

DLLIST_SOURCES	:= $(addprefix $(DLLIST_DIR)/,$(DLLIST_SOURCES))

SRC		+= $(DLLIST_SOURCES)
HEADERS	+= ft_dllist.h
