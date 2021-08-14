#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* has forgot it :), declaration of syscall ! */
#include <string.h>
#include <sys/utsname.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	unsigned long syscall_nr = 63; /* uname */
	struct utsname buff;
	(void)argc;
	(void)argv;

	memset(&buff, 0, sizeof(struct utsname));
	if (syscall(syscall_nr, &buff)){
		perror("uname");
		exit(EXIT_FAILURE);
	}
	printf(">>> Operating system release is %s\n", buff.release);

	exit(EXIT_SUCCESS);
}
