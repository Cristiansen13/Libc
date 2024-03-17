#pragma once
struct timespec {
    long tv_tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *t1, struct timespec *t2);
unsigned int sleep(unsigned int seconds);
