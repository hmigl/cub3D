SHELL := /bin/sh

NAME := cub3d
OBJDIR := objdir

CFLAGS += $(INCLUDE) -Wall -Wextra -g
LDLIBS += -lm -lft
LDFLAGS += -L$(LIBFTDIR)
INCLUDE = -I./include -I$(LIBFTDIR)/include

LIBFTDIR = ./libs/libft
LIBFT := $(LIBFTDIR)/libft.a

vpath %.c $(shell find src -type d)

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

SRC = cub3d.c

SRC += parse_map.c

$(OBJDIR)/%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

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
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C$(LIBFTDIR) --no-print-directory
	$(RM) $(NAME)

re: fclean all

.PHONY: all re
