SRCS	= exit.c\
		  hook.c\
		  init.c\
		  init_text.c\
		  init_text_patrol.c\
		  main.c\
		  parsing.c\
		  parsing_utils.c\
		  patrol.c\
		  patrol_utils.c\
		  so_long_utils.c\
		  texture.c\
		  texture_patrol.c
 
OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

%.o:		%.c so_long.h
			${CC} ${CFLAGS} -o $@ -c $< -I./so_long.h

all:		libft mlx ${NAME}

${NAME}:	${OBJS}
			${CC} -L mlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} libft/libft.a mlx/libmlx.a

libft:
			make -C libft all

mlx:
			make -C mlx all

clean:
			make clean -C libft
			make clean -C mlx
			${RM} ${OBJS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all

run:		all
			./so_long map.ber

.PHONY: all clean fclean re mlx libft run