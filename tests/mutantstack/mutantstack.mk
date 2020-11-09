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

MSTACK_DIR		= mutantstack

MSTACK_SOURCES	= mutantstack.cpp
MSTACK_SOURCES	:= $(addprefix $(MSTACK_DIR)/,$(MSTACK_SOURCES))

SRC		+= $(MSTACK_SOURCES)
