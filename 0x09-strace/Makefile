  
.PHONY = strace_0 clean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
OBJDIR = objs/

SRC0 = 0-ptrace.c
OBJ0 = $(addprefix $(OBJDIR), $(SRC0:%.c=%.o))

strace_0: syscalls.h $(OBJDIR) $(OBJ0)
	gcc $(CFLAGS) -o $@ $(OBJ0)

$(OBJDIR)%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	-rm -rf $(OBJDIR)
	-rm -r strace_0

re: clean strace_0