# OBJS = $(SRCS:.c=.o)

# CC = gcc

# RM = rm -f

# FLAGS = -g -Wall -Wextra -Werror

# all:	$(NAME)

# run:	all

# 	./miniRT

# %.o: %.c
# 	$(CC) $(FLAGS) -Imlx -c $< -o $@

# $(NAME):	$(OBJS)
# 			make -C ./minilibx_mms_20200219
# 			cp ./minilibx_mms_20200219/libmlx.dylib .
# 			$(CC) $(FLAGS) $(OBJS) -Lminilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# clean:
# 	$(RM) $(OBJS)
# 	make clean -C minilibx_mms_20200219
# 	$(RM) libmlx.dylib
# fclean: clean
# 	$(RM) $(NAME)

# re:				fclean all

# .PHONY: all, clean, fclean, re
CC =			gcc

FLAGS =			-Wall -Wextra -Werror -g

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS =		./srcs/

DIR_OBJS =		./

LIBMLX = 		-lmlx \
				libmlx.dylib \
				-framework AppKit \
				-framework OpenGL

SAVE =			-fsanitize=address

SRCS = main.c \
bmp/bmp.c \
initialization/initialization.c \
calculations/calculations.c \
calculations/key_proc.c \
calculations/get_shadow.c \
calculations/ray_and_sphere_intersection.c \
calculations/moller_trumbore.c \
calculations/ray_and_cylinder_intersection.c \
calculations/ray_and_plane_intersection.c \
calculations/ray_and_square_intersection.c \
different_errors/different_errors.c \
vector_operations/vector_operations.c \
vector_operations/vector_operations_2.c \
scenes/create_canvas.c \
scenes/create_colour.c \
scenes/colour_operations.c scenes/camera.c scenes/light.c \
scenes/colour.c scenes/get_colour.c  \
subfunctions/ft_lobject_add_back.c \
subfunctions/ft_lobject_new.c \
subfunctions/ft_lstsize.c subfunctions/ft_split.c \
subfunctions/get_next_line_utils.c subfunctions/ft_strncmp.c \
subfunctions/get_next_line.c subfunctions/ft_atoi_fractional.c \
subfunctions/ft_atoi.c  subfunctions/free_split.c \
investigation_of_data/create_scene.c \
investigation_of_data/number_of_words.c \
investigation_of_data/get_coordinates.c \
investigation_of_data/ft_get_data.c \
get_objects/get_ambient.c get_objects/get_camera.c \
get_objects/get_cylinder.c get_objects/get_light.c \
get_objects/get_plane.c get_objects/get_resolution.c \
get_objects/get_sphere.c get_objects/get_square.c \
get_objects/get_triangle.c \
objects/cylinder.c objects/plane.c objects/sphere.c \
objects/square.c objects/triangle.c \
objects_normal/objects_normal.c


COMPIL =		$(FLAGS)

OBJS =			$(SRCS:.c=.o)

NAME = miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
				@make -C ./minilibx_mms
				# @make -C ./minilibx_opengl
				@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				# @cp ./minilibx_opengl/libmlx.a libmlx.a
				$(CC) $(COMPIL) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)

%.o: %.c
				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

bonus:

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				@make clean -C ./minilibx_mms
				$(RM) libmlx.dylib
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
