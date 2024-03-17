// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long result = syscall(9, addr, length, prot, flags, fd, offset);
	if (result < 0) {
		errno = -result;
		return MAP_FAILED;
	}
	return (void*)result;
	/* TODO: Implement mmap(). */
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long result = syscall(25, old_address, old_size, new_size, flags);
	if (result < 0) {
		errno = -result;
		return MAP_FAILED;
	}
	return (void*)result;
	/* TODO: Implement mremap(). */
}

int munmap(void *addr, size_t length)
{
	int result = syscall(11, addr, length);
	if (result < 0) {
		errno = -result;
		return 0;
	}
	/* TODO: Implement munmap(). */
	return result;
}
