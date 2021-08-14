int
main(int argc, char *argv[])
{
	unsigned long syscall_nr = 60;
	long status = 77;
	(void) argc;
	(void) argv;

	asm("movq %0, %%rax; movq %1, %%rdi; syscall;"::"m"(syscall_nr), "m"(status): "rax", "rdi");
}
