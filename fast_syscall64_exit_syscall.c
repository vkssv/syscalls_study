#include <stdint.h>

int
main(int argc, char *argv[])
{
	uint64_t syscall_nr = 60;
	int64_t status = 77;
	(void) argc;
	(void) argv;

	asm("movq %0, %%rax; movq %1, %%rdi; syscall;"::"m"(syscall_nr), "m"(status): "rax", "rdi");
}
