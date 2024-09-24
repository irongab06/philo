#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long get_current_time_in_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}