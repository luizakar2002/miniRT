DIR_HEADERS = ./includes/

DIR_SRCS	= ./

SRC			= utils/error_exit.c \
			  utils/free_scene.c \
			  intersections/sphere_intersect.c \
			  ray_tracing/trace_ray.c \
			  scene/camera.c \
			  scene/scene.c \
			  figures/sphere.c \
			  geometry/vector.c \
			  main.c \

SRCS		= $(addprefix $(DIR_SRCS), $(SRC))

OBJS		= $(SRCS:.c=.o)

NAME		= miniRT

LIBMLX		= libmlx.dylib

GCC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

%.o: %.c
			$(GCC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./minilibx_mms_20200219
			cp ./minilibx_mms_20200219/libmlx.dylib .
			$(GCC) $(CFLAGS) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
					make clean -C ./minilibx_mms_20200219
					$(RM) $(LIBMLX)
					$(RM) $(NAME)

RE:			fclean all

PHONY:		all clean fclean re
