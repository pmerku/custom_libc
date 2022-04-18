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

UNISTD_DIR		= ft_unistd

UNISTD_SOURCES	= ft_unistd.cpp
UNISTD_SOURCES	:= $(addprefix $(UNISTD_DIR)/,$(UNISTD_SOURCES))

SRC		+= $(UNISTD_SOURCES)