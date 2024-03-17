// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <stddef.h>
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t len)
{
	int ret = syscall(1, fd, buf, len);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}

ssize_t read(int fd, void *buf, size_t len)
{
	int ret =  syscall(0, fd, buf, len);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
