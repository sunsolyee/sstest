#include "time.h"

time_t time::millisecond()
{
    struct timeval time_now
    {
    };
    gettimeofday(&time_now, mullptr);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    return msecs_time;
}