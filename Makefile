SHELL := /bin/sh

NAME := cub3d
OBJDIR := objdir

CFLAGS += -Wall -Wextra -g
LDLIBS += -lm
LDFLAGS +=

vpath %.c src

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

SRC = cub3d.c

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
