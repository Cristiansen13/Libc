#include <time.h>
#include <internal/syscall.h>
#include <unistd.h>
#include <internal/types.h>
#include <errno.h>

int nanosleep(const struct timespec *t1, struct timespec *t2) {
    int result = syscall(35, t1, t2);
    if (result < 0) {
        errno = -result;
        return -1;
    }
    return 0;
}
unsigned int sleep(unsigned int seconds) {
    struct timespec rem, req = {seconds, 0};
    return nanosleep(&req, &rem);
}
