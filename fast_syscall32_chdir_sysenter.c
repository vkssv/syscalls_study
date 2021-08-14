#include <stdlib.h> /* EXIT_FAILURE */
#include <stdio.h> /* printf, perror */
#include <sys/auxv.h> /* getauxval*/
#include <unistd.h> /* getcwd */
#include <limits.h> /* PATH_MAX */
#include <errno.h>

int
main(int argc, char *argv[]){

	char new_path[PATH_MAX] = "/tmp";
	char *current_path;
	unsigned long vsyscall_addr;
	unsigned int syscall_nr = 12; /* chdir */
	(void) argc;
	(void) argv;

	current_path = getcwd(NULL, 0);
	if (!current_path){
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	printf(">>> cwd is (%s)\n", current_path);
	free(current_path);

	vsyscall_addr = getauxval(AT_SYSINFO);
	asm("movl %0, %%eax; movl %1, %%ebx; call *%2;" :: "m"(syscall_nr), "g"(new_path), "m"(vsyscall_addr): "eax", "ebx");

	/* check, that chdir was performed */
	current_path = getcwd(NULL, 0);
	printf(">>> cwd is (%s)\n", current_path);
	free(current_path);

	exit(EXIT_SUCCESS);
}

