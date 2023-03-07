SHELL := /bin/sh

NAME := cub3D
OBJDIR := objdir

CFLAGS += $(INCLUDE) -Wall -Wextra -g -MMD -MP
LDLIBS += -lm -lft -lmlx -lXext -lX11
LDFLAGS += -L$(LIBFTDIR)
INCLUDE = -I./include -I$(LIBFTDIR)/include

LIBFTDIR = ./libs/libft
LIBFT := $(LIBFTDIR)/libft.a

vpath %.c $(shell find src -type d)

# MAIN
SRC += cub3d.c release_memory.c error_handling.c \
      exit_game_gracefully.c

# PARSER
SRC += parse_scene_desc.c extract_scene_elements.c extract_texture_path.c \
       extract_rgb_color.c extract_scene_map.c trim_line.c \
       map_as_list_validation.c map_as_2d_array_validation.c position_setup.c \
	   texture_utils.c 

# SETUP
SRC += mlx_setup.c vectors_setup.c textures_setup.c

# RAYCASTER
SRC += render.c raycasting.c dda.c texture.c

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEPS = $(OBJS:.o=.d)

$(OBJDIR)/%.o: %.c Makefile
	$(COMPILE.c) $(OUTPUT_OPTION) $<

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $^ $(OUTPUT_OPTION) $(LDLIBS) $(LDFLAGS)

options:
	@echo "$(NAME) build options:"
	@echo "CFLAGS        = $(CFLAGS)"
	@echo "LDFLAGS       = $(LDFLAGS)"
	@echo "LDLIBS        = $(LDLIBS)"
	@echo "CC            = $(CC)"

$(LIBFT):
	$(MAKE) -j4 -C$(LIBFTDIR) --no-print-directory

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $@

clean:
	$(MAKE) $@ -C$(LIBFTDIR) --no-print-directory
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) $@ -C$(LIBFTDIR) --no-print-directory
	$(RM) $(NAME)

re: fclean all

.PHONY: all re

-include $(DEPS)
