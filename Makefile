SHELL := /bin/sh

NAME := cub3D
OBJDIR := objdir

CFLAGS += $(INCLUDE) -Wall -Wextra -g -MMD -MP
LDLIBS += -lm -lft
LDFLAGS += -L$(LIBFTDIR)
LINK.o += $(LDLIBS)
INCLUDE = -I./include -I$(LIBFTDIR)/include

LIBFTDIR = ./libs/libft
LIBFT := $(LIBFTDIR)/libft.a

vpath %.c $(shell find src -type d)

SRC = cub3d.c release_memory.c

SRC += parse_scene_desc.c extract_scene_elements.c extract_texture_path.c \
       extract_rgb_color.c extract_scene_map.c trim_line.c \
       map_as_list_validation.c

SRC += error_handling.c

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEPS = $(OBJS:.o=.d)

$(OBJDIR)/%.o: %.c Makefile
	$(COMPILE.c) $(OUTPUT_OPTION) $<

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(LINK.o) $(OUTPUT_OPTION) $^

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
