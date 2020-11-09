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

CTYPE_DIR		= ft_ctype

CTYPE_SOURCES	= ft_ctype.cpp
CTYPE_SOURCES	:= $(addprefix $(CTYPE_DIR)/,$(CTYPE_SOURCES))

SRC		+= $(CTYPE_SOURCES)
