# var
CC = gcc

NVCC = /Developer/NVIDIA/CUDA-5.5/bin/nvcc

NAME = rtv1

CFLAGS = -Wall -Wextra -Werror

INC = -I /usr/include/mlx.h -L/usr/local/lib -lmlx -framework OPENGL -framework AppKit

OBJDIR = obj/

HEADERDIR = .

SRCS = main.c				\
	   raytracer.c			\
	   load_tab_obj.c		\
	   obj_sphere_plane.c	\
	   obj_cyl_cone.c		\
	   obj_tri_circ.c		\
	   colour_phong.c		\
	   input.c				\
	   ft_ahextoi.c			\
	   exit.c				\
	   validate_map.c		\
	   camera.c				\
	   v3d_calc.c			\
	   v3d_calc2.c			\
	   v3d_calc3.c			\
	   ft_image.c			\
	   ft_convert_base.c	\

HEADER = $(NAME).h

OBJS = $(addprefix $(OBJDIR),$(subst .c,.o,$(SRCS)))

INCLUDES = -I libft/includes

define colorecho
      @tput setaf 14
      @echo $1
      @tput sgr0
endef

define colorecho2
      @tput setaf 2
      @echo $1
      @tput sgr0
endef

.PHONY: all clean fclean re proper libft

all: libft $(NAME) $(CUDA_NAME)

$(NAME): qme libft/libft.a $(OBJS) $(HEADER)
	@$(call colorecho,"Compiling program.")
	@$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME) $(INCLUDES) -L libft -lft
	@clear
	@$(call colorecho,"Done Compiling.")

libft:
	make -C libft

$(OBJS): | $(OBJDIR)

$(OBJDIR)%.o : %.cu $(HEADER)
	@$(call colorecho,"Compiling object.")
	$(NVCC) -c $(CUDA_CFLAGS) $< -o $@ $(INCLUDES)

$(OBJDIR)%.o : %.c $(HEADER)
	@$(call colorecho,"Compiling object.")
	@$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

$(OBJDIR):
	@$(call colorecho,"Checking if objects folder needs to be made")
	@if [ ! -d "$(OBJDIR)" ]; then \
		mkdir $(OBJDIR);\
		fi

clean:
	@$(call colorecho,"Cleaning libft objects")
	@make clean -C libft
	@$(call colorecho,"Cleaning Objects")
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)
	@$(call colorecho,"Done cleaning.")

fclean: clean
	@$(call colorecho,"Cleaning Libft")
	@rm -rf libft/libft.a
	@$(call colorecho,"Removing evecutable")
	@rm -rf $(NAME)
	@clear
	@$(call colorecho,"Done cleaning everything.")

proper: all clean

re: fclean all

format: qme norme me
	@$(call colorecho2,"All good!\n")

norme:
	@$(call colorecho2,"Norme:\n")
	@norminette $(SRCS)
	@norminette $(HEADER)

me: qme
	@$(call colorecho2,"Author:\n")
	cat -e author

qme:
	@if [ ! -f author ]; then \
		whoami > author; git add author; \
		fi

