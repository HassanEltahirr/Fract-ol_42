NAME = fractol


SRCS = main.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -Imlx/mlh.h
CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBFLAGS = -Imlx


ALL: $(NAME)

$(NAME): $(OBJS)
	make -C ./mlx
	$(CC) $(OBJS) $(INCLUDE) $(LIBFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)