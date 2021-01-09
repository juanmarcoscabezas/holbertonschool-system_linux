#include "syscalls.h"

#include <stddef.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <string.h>

int main(int ac, char **av, char **en)
{
	pid_t child = 0;
	int status = 0, flag = 0;
	struct user_regs_struct regs;

	if (ac < 2)
	{
		printf("./strace_1 command [args...]\n");
		return (1);
	}
	setbuf(stdout, NULL);
	child = fork();
	if (child == 0)
	{
		ptrace(PTRACE_TRACEME, child, NULL, NULL);
		raise(SIGSTOP);
		execve(av[1], &(av[1]), en);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (0);
		ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		while (wait(&status) && !WIFEXITED(status))
		{
			if (flag)
				(printf("\n"), flag = 0);
			memset(&regs, 0, sizeof(regs));
			ptrace(PTRACE_GETREGS, child, NULL, &regs);
			if (WSTOPSIG(status) == SIGTRAP && (long) regs.rax == -38)
			{
				flag = 1;
				printf("%s", (char *) syscalls_64_g[(unsigned long)regs.orig_rax].name);
			}
			ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		}
		printf("\n");
	}
	return (0);
}
