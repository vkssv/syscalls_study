#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	uint64_t syscall_nr = 60; /* exit */
	int64_t status = 77;
	(void) argc;
	(void) argv;

	syscall(syscall_nr, status);
}
