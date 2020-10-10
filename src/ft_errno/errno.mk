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

LIBFT_DIR		= ft_errno

LIBFT_SOURCES	= ft_errno.c
LIBFT_SOURCES 	:= $(addprefix $(LIBFT_DIR)/,$(LIBFT_SOURCES))

SRC 	+= $(LIBFT_SOURCES)
HEADERS	+= ft_errno.h
