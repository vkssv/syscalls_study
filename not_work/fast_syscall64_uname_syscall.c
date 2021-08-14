#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <errno.h>


int
main(int argc, char *argv[])
{
	unsigned long syscall_nr = 63;
	struct utsname utsname_buf;
	struct utsname *buff;
	struct utsname *filled_uname;

	memset(&utsname_buf, 0, sizeof(struct utsname));
	uname(&utsname_buf);

	printf(">>> kernel version is (%s)\n", utsname_buf.sysname);
	memset(&utsname_buf, 0, sizeof(struct utsname));
	buff = &utsname_buf;

	asm("movq %0, %%rax; movq %1, %%rdi; syscall; ": "=a"(filled_uname): "m"(syscall_nr), "m"(buff));

	printf(">>> buff addr utsname_buf (%p)\n", &utsname_buf);
	printf(">>> returned answ (%p)\n", filled_uname);
	printf(">>> kernel version is (%s)\n", filled_uname->sysname);
}
