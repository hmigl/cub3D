SHELL := /bin/sh

NAME := cub3d
OBJDIR := objdir

CFLAGS += -I./include -Wall -Wextra -g
LDLIBS += -lm
LDFLAGS +=

vpath %.c src

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

SRC = cub3d.c

SRC += parse_map.c

$(OBJDIR)/%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

all: $(NAME)

options:
	@echo "$(NAME) build options:"
	@echo "CFLAGS        = $(CFLAGS)"
	@echo "LDFLAGS       = $(LDFLAGS)"
	@echo "LDLIBS        = $(LDLIBS)"
	@echo "CC            = $(CC)"

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re
