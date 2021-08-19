#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

int
main(int argc, char *argv[]){
	uint64_t syscall_nr = 2; /* fork */
	pid_t pid_child;
	(void) argc;
	(void) argv;

	asm("movl %0, %%eax; int $0x80;": "=a"(pid_child):"0"(syscall_nr));
	printf(">>> got pid via inline asm by executing $0x80 with syscall_nr (%ld): (%ld)\n",
	       syscall_nr, (uint64_t) pid_child);

	exit(EXIT_SUCCESS);

}
