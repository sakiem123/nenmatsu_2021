#ifndef LOG_H
#define LOG_H
#include <stdio.h>

#define LDEBUG_LOG(...) {\
  printf("DEBUG_LOG::Fname:%s,line:%d,func:%s::",\
    __FILE__, __LINE__, __func__);\
  printf(__VA_ARGS__);\
  printf("\n");\
}

#endif
