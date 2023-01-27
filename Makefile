SHELL := /bin/sh

NAME := cub3d
OBJDIR := objdir

CFLAGS += $(INCLUDE) -Wall -Wextra -g
LDLIBS += -lm -lft
LDFLAGS += -L$(LIBFTDIR)
LINK.o += $(LDLIBS)
INCLUDE = -I./include -I$(LIBFTDIR)/include

LIBFTDIR = ./libs/libft
LIBFT := $(LIBFTDIR)/libft.a

vpath %.c $(shell find src -type d)

SRC = cub3d.c

SRC += parse_map.c extract_scene_elements.c extract_texture_path.c \
       trim_line.c

SRC += error_handling.c

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEPS = $(OBJS:.o=.d)

$(OBJDIR)/%.o: %.c Makefile
	$(COMPILE.c) -MMD -MP $(OUTPUT_OPTION) $<

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
	$(MAKE) clean -C$(LIBFTDIR) --no-print-directory
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) fclean -C$(LIBFTDIR) --no-print-directory
	$(RM) $(NAME)

re: fclean all

.PHONY: all re

-include $(DEPS)
