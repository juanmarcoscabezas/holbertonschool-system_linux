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
	if (child_process == 0)
	{
		ptrace(PTRACE_TRACEME, child_process, NULL, NULL);
		raise(SIGSTOP);
		execve(argv[1], &(argv[1]), argp);
	}
	else
	{
		wait(&process_s);
		if (WIFEXITED(process_s))
			return (0);
		ptrace(PTRACE_SYSCALL, child_process, NULL, NULL);
		while (wait(&process_s) && !WIFEXITED(process_s))
		{
			memset(&regs, 0, sizeof(regs));
			ptrace(PTRACE_GETREGS, child_process, NULL, &regs);
			if (WSTOPSIG(process_s) == SIGTRAP && (long) regs.rax == -38)
				printf("%lu\n", (unsigned long) regs.orig_rax);
			ptrace(PTRACE_SYSCALL, child_process, NULL, NULL);
		}
	}
	return (0);
}
