#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/personality.h>
#include <sys/utsname.h>
#include <errno.h>

int
main(int argc, char *argv[])
{
	unsigned long syscall_nr = 135;
	struct utsname utsname_buf;
	unsigned long persona32 = 0x20008; /* UNAME26 | PER_LINUX32, not work for now, will fix it */
	unsigned long prev_persona;
	unsigned long prev_persona2;
	(void) argc;
	(void) argv;

	printf(">>> current persona is 0x%04x\n", personality(0xffffffff));

	memset(&utsname_buf, 0, sizeof(struct utsname));
	uname(&utsname_buf);

	printf(">>> kernel version is (%s)\n", utsname_buf.release);

	asm("movq %0, %%rax; movq %1, %%rdi; syscall; ": "=a"(prev_persona), "=d"(prev_persona2): "m"(syscall_nr), "m"(persona32));

	printf(">>> prev persona was 0x%lx\n", prev_persona);
	printf(">>> prev persona was 0x%lx\n", prev_persona2);

	memset(&utsname_buf, 0, sizeof(struct utsname));
	uname(&utsname_buf);
	printf(">>> kernel version is (%s)\n", utsname_buf.release);
}
