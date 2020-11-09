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

LIBFT_DIR		= ft_libft

LIBFT_SOURCES	= ft_libft.cpp
LIBFT_SOURCES 	:= $(addprefix $(LIBFT_DIR)/,$(LIBFT_SOURCES))

SRC 	+= $(LIBFT_SOURCES)
