#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	unsigned long syscall_nr = 60; /* exit */
	long status = 77;
	(void) argc;
	(void) argv;

	syscall(syscall_nr, status);
}
