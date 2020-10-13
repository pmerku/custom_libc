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

ERRNO_DIR		= ft_errno

ERRNO_SOURCES	= ft_errno.c
ERRNO_SOURCES 	:= $(addprefix $(ERRNO_DIR)/,$(ERRNO_SOURCES))

SRC 	+= $(ERRNO_SOURCES)
HEADERS	+= ft_errno.h
