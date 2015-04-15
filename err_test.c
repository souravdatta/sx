#include "err.h"
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    error("expected 2 got %d\n", 4);
    error("that is so wrong...\n");
    
    error_try((2 + 2) == 3);
    error_try(open("./junk.txt", O_RDONLY) >= 0);
    error_try(open("./err_test.c", O_RDONLY) >= 0);

    error_quit("Zibber %s\n", "zabber");
    return 0;
}
