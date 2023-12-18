#include <unistd.h>     /* Support all standards    */
#include <stdio.h>
#include <sys/mman.h>   /* Memory locking functions */

#define DATA_SIZE 2048

int lock_memory(char *addr, size_t size) {
    unsigned long page_offset, page_size;

    page_size = sysconf(_SC_PAGE_SIZE);
    page_offset = (unsigned long) addr % page_size;
    printf(">>> %s, page_size=%ld, page_offset=%ld\n", __func__, page_size, page_offset);

    addr -= page_offset;  /* Adjust addr to page boundary */
    size += page_offset;  /* Adjust size with page_offset */
    void *new_pos = &addr;
    printf(">>> %s, adjusted addr=%p, adjusted size=%zu\n", __func__, new_pos, size);

    return ( mlock(addr, size) );  /* Lock the memory */
}

int unlock_memory(char *addr, size_t size) {
    unsigned long page_offset, page_size;

    page_size = sysconf(_SC_PAGE_SIZE);
    page_offset = (unsigned long) addr % page_size;
    printf(">>> %s, page_size=%ld, page_offset=%ld\n", __func__, page_size, page_offset);

    addr -= page_offset;  /* Adjust addr to page boundary */
    size += page_offset;  /* Adjust size with page_offset */

    void *new_pos = &addr;
    printf(">>> %s, adjusted addr=%p, adjusted size=%zu\n", __func__, new_pos, size);

    return ( munlock(addr, size) );  /* Unlock the memory */
}

int main() {
    char data[DATA_SIZE];
    void *addr = &data;
    printf(">>> %s, start addr=%p\n", __func__, addr);

    if ( lock_memory(data, DATA_SIZE) == -1 ) {
        perror("lock_memory");
    }

    printf(">>> %s: Memory locked\n", __func__);

           /* Do work here */
    if ( unlock_memory(data, DATA_SIZE) == -1 ) {
        perror("unlock_memory");
    }

    printf(">>> %s: Memory unlocked\n", __func__);

}