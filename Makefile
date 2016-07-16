# var
CC = gcc
NVCC = /Developer/NVIDIA/CUDA-5.5/bin/nvcc
NAME = rtv1
CFLAGS = -Wall -Wextra -Werror
INC = -I /usr/include/mlx.h -L/usr/local/lib -lmlx -framework OPENGL -framework AppKit
OBJDIR = obj/
HEADERDIR = .
SRCS = main.c \
	   raytracer.c \
	   load_tab_obj.c \
	   obj_sphere_plane.c \
	   obj_cyl_cone.c \
	   obj_tri_circ.c \
	   colour_phong.c \
	   input.c \
	   ft_ahextoi.c \
	   exit.c \

HEADER = $(NAME).h
OBJS = $(addprefix $(OBJDIR),$(subst .c,.o,$(SRCS)))
INCLUDES = -I libft/includes

.PHONY: all clean fclean re proper libft

all: libft $(NAME) $(CUDA_NAME)

$(NAME): libft/libft.a $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME) $(INCLUDES) -L libft -lft

libft:
	make -C libft

$(OBJS): | $(OBJDIR)

$(OBJDIR)%.o : %.cu $(HEADER)
	$(NVCC) -c $(CUDA_CFLAGS) $< -o $@ $(INCLUDES)

$(OBJDIR)%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

$(OBJDIR):
	@if [ ! -d "$(OBJDIR)" ]; then \
		mkdir $(OBJDIR);\
		fi

clean:
	@make clean -C libft
	rm -rf $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

proper: all clean

re: fclean all
