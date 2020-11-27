#include "syscalls.h"

#include <stddef.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <string.h>

int main(int argc, char *argv[], char *argp[])
{
	int process_s = 0;
	struct user_regs_struct regs;
	pid_t child_process = 0;

	if (argc < 2)
	{
		printf("./strace_0 command [args...]\n");
		return (1);
	}
	setbuf(stdout, NULL);
	child_process = fork();

	return (0);
}
