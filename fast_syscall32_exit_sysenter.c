#include <stddef.h> /* NULL */
#include <elf.h>

int
main(int argc, char *argv[], char *envp[])
{
	unsigned int syscall_nr = 1; /* simple exit */
	int exit_status = 13;
	Elf32_auxv_t *auxv;
	(void) argc;
	(void) argv;

	while (*envp++ != NULL);
	/* envp is now pointed at the auxilliary vectors, since we've iterate
	 * through the environment variables.
	 */

	for (auxv = (Elf32_auxv_t *)envp; auxv->a_type != AT_NULL; auxv++) {
		if(auxv->a_type == AT_SYSINFO) {  /* find __kernel_vsyscall addr*/
			break;
		}
	}
	/* syscall_nr in eax, status arg in ebx, call __kernel_vsyscall to
	 * trigger sysenter.
	 */
	asm("movl %0, %%eax; movl %1, %%ebx; call *%2;":: "m"(syscall_nr), "m"(exit_status), "m"(auxv->a_un.a_val): "eax", "ebx");

}
