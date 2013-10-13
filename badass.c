#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <errno.h>

static const int timeout = 6;

#define LIB_NAME "libbadass.so"

int main (int argc, char **argv)
{
    /* shut up gcc! */
    (void) argc; (void) (argv);

    dlerror ();
    void *handle = dlopen (LIB_NAME, RTLD_LAZY);

    if ( handle == NULL ) {
        
        printf ("Unable to open " LIB_NAME ". Error: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    dlclose (handle);

    printf ("Doing stuff...\n");
    sleep (timeout);
    return EXIT_SUCCESS;
}
