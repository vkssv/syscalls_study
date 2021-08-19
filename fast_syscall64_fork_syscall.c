#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

int
main(int argc, char *argv[]){
	uint64_t syscall_nr = 57; /* fork */
	volatile int64_t pid_child;
	(void) argc;
	(void) argv;

	asm("movq $57, %%rax; syscall; ": "=a"(pid_child));
	printf(">>> got pid via inline asm by executing syscall with syscall_nr (%ld): (%ld)\n",
	       syscall_nr, (int64_t) pid_child);

}
