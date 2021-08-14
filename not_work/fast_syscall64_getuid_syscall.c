#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>



int
main(int argc, char *argv[])
{
	unsigned long syscall_nr = 102;
	unsigned long uid;
	unsigned long ret;

	ret = getuid();
	printf(">>> ret is 0x%04lx\n", ret);
	printf(">>> ret is %ld\n", ret);

	asm("movq %0, %%rax; syscall; ": "=a"(uid): "m"(syscall_nr));

	printf(">>> uid is %ld\n", uid);
	printf(">>> uid is 0x%04lx\n", uid);
}
