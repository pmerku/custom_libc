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

STDIO_DIR		= ft_stdio

STDIO_SOURCES 	=
STDIO_SOURCES 	:= $(addprefix $(STDIO_DIR)/,$(STDIO_SOURCES))

SRC 	+= $(STDIO_SOURCES)
HEADERS	+= ft_stdio.h
