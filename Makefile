NAME := LC-3VM

override SRCDIR := srcs/

override BUILDDIR := .build/

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

MAIN := main

BASENAME := $(MAIN)

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

CC := cc

CFLAGS := -Wall -Wextra -Werror -Wunreachable-code

CPPFLAGS := -Iincludes

DEPSFLAGS := -MD -MP -MF

MAKEFLAGS += --no-print-directory

.DEFAULT_GOAL = all

-include $(DEPS)

.PHONY: json
json:
	@compiledb $(MAKE)

.PHONY: all
all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(DEPDIR) $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@

$(DEPDIR) $(OBJDIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
