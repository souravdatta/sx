#ifndef __ERR_H__
#define __ERR_H__

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>

void error(const char *fmt, ...);
void error_quit(const char *fmt, ...);

#define error_try(op)							\
    do {								\
	errno = 0;							\
	if (!(op)) {							\
	    error(#op " -- %s\n", strerror(errno));	\
	}								\
    } while (0)

#endif
