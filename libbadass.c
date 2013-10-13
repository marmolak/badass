#include <pthread.h>
#include <unistd.h>

static const int timeout = 5;

void initialize (void) __attribute__((constructor));

static int x = 10;
static pthread_t th;

static void *just_run (void *data)
{
    (void) data;

    sleep (timeout);
    x = 100;
    
    return NULL;
}

void initialize (void)
{
    pthread_create (&th, NULL, &just_run, NULL);
}
