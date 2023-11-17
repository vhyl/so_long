# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhyl <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 22:53:02 by vhyl              #+#    #+#              #
#    Updated: 2023/01/16 19:49:04 by vhyl             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCS = libft.h
LIBC = ar rcs
CC = cc
OBJ_DIR = objects/
CFLAGS = -Wall -Wextra -Werror

SRC	= $(addprefix $(SRC_LIBFT_DIR), $(addsuffix .c, $(SRC_LIBFT))) \
		$(addprefix $(SRC_PRINTF_DIR), $(addsuffix .c, $(SRC_PRINTF)))

SRC_LIBFT_DIR = src_libft/
SRC_PRINTF_DIR = src_ft_printf/

SRC_LIBFT = ft_atoi ft_strnstr ft_memmove ft_memchr ft_strrchr \
	ft_memcmp ft_tolower ft_isalnum ft_strlen \
	ft_isdigit ft_isprint ft_toupper ft_strlcat ft_bzero \
	ft_isalpha ft_memset ft_isascii ft_strlcpy ft_memcpy \
	ft_strncmp ft_strdup ft_calloc ft_itoa ft_putchar_fd \
	ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_substr \
	ft_strjoin ft_strmapi ft_split ft_strchr ft_striteri \
	ft_strtrim ft_lstiter ft_lstmap ft_lstclear ft_lstadd_back \
	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstdelone

SRC_PRINTF = ft_print_char ft_print_decimal ft_print_hexa ft_print_ptr \
	ft_print_string ft_print_unsigned ft_printf
		
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_LIBFT))) \
	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_PRINTF)))

all: ${NAME}

$(OBJ_DIR)%.o:	$(SRC_LIBFT_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o:	$(SRC_PRINTF_DIR)%.c 
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 		$(OBJ)
				@$(LIBC) $(NAME) $(OBJ)

clean:
	rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
