#include <stdio.h>
#include <sys/types.h>

int
main(int argc, char *argv[]){
	unsigned long syscall_nr = 57; /* fork */
	long pid_child;
	(void) argc;
	(void) argv;

	asm("movq $57, %%rax; syscall; ": "=a"(pid_child));
	printf(">>> got pid via inline asm by executing syscall with syscall_nr (%ld): (%ld)\n",
	       syscall_nr, (long) pid_child);

}
