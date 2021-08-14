# syscalls_study with inline assembly for i386, x86-64, x32
#
# 1. examples of legacy syscall int $0x80:
# - legacy_syscall_exit_with_sw_irq.c
# - legacy_syscall_fork_with_sw_irq.c
#
# 2. examples of 32-bit fast syscalls (__kernel_vsyscall, sysenter/sysexit)
# - fast_syscall32_exit_sysenter.c
# - fast_syscall32_chdir_sysenter.c
#
# 3. examples of 64-bit fast syscalls (syscall/sysret)
# - fast_syscall64_exit_syscall.c
# - fast_syscall64_fork_syscall.c
#
# 4. examples of glibc syscall wrapper usage (may be clone3 case)
# - glibc_syscall_wrapper_exit.c
# - glibc_syscall_wrapper_uname.c
#
# 5. not_work, more examples for fast 64-bit syscalls to fix later.
#
