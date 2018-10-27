#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#define LOWER_BOUND_FN(Fname, PtrType, ValType) \
  PtrType Fname(PtrType start, PtrType end, ValType v, int (*cmpfn)(ValType, ValType)) { \
  while (start != end) { \
  int *middle = start + ((end - start) / 2); \
    if (cmpfn(*middle, v) < 0) { \
      start = middle + 1; \
    } \
    else { \
      end = middle; \
    } \
  } \
  return start; \
  }

#endif
