#include "stdio.h"
#include "util.h"
#include <stdlib.h>

#pragma once

#define TEST(test_name, block)                                                 \
  {                                                                            \
    char name[] = #test_name;                                                  \
    if (name[0] != '\0' && name[0] != '!') {                                   \
      printf("%sRunning Test%s: %s%s%s\n", BLUE, WHITE, BOLD, name, STANDARD); \
      block;                                                                   \
      printf("Test %s%s%s, %spassed!%s\n", BOLD, name, STANDARD, GREEN,        \
             WHITE);                                                           \
    }                                                                          \
  }

#define ASSERT(cond)                                                           \
  {                                                                            \
    if (cond) {                                                                \
      ;                                                                        \
    } else {                                                                   \
      printf("%sAssertion failed%s: %s is not equal\n", RED, WHITE, #cond);    \
      exit(1);                                                                 \
    }                                                                          \
  }