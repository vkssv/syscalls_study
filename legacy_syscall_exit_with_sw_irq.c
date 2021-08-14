int main(int argc, char *argv[])
{
	unsigned int syscall_nr = 1;
	int exit_status = 13;
	(void) argc;
	(void) argv;

	asm ("movl %0, %%eax; movl %1, %%ebx; int $0x80;"::"m"(syscall_nr), "m"(exit_status): "eax", "ebx");
}
