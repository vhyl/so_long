NAME		=	so_long
LIBFT_F		=	libft/
LIBFT		=	libft.a
LIBMLX		=	./.mlx42
LIBS		=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LHEADERS	=	-I ./include -I $(LIBMLX)/include
CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
CMFLAGS		=	-DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B build
OBJ_DIR		=	objects/

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_S)))
SRC_DIR		=	src/
SRC_S		=	ft_so_long \
				ft_init \
				ft_utils \
				ft_checker \

OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_S)))

all:			libmlx $(LIBFT) $(NAME)

bonus:			all

libmlx:
				@cmake $(LIBMLX) $(CMFLAGS) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 		$(OBJ)
				@$(CC) $(CFLAGS) $(SRC) libft.a $(LIBS) $(LHEADERS) -o $(NAME)

$(LIBFT):		
				@make -s -C $(LIBFT_F)
				@cp libft/libft.a .

clean:
				@rm -rf $(OBJ_DIR)
				@rm -f $(LIBFT)
				@make fclean -s -C $(LIBFT_F)
				@rm -rf $(LIBMLX)/build

fclean:			clean
				@rm -f $(NAME)

re: 			fclean all

.PHONY: all clean fclean re bonus