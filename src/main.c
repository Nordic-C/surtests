#include "tests.h"
#include <string.h>

void test();

int main(void) { test(); }

void test() {
  TEST(my_test, {
    int x = 400;
    int y = 200;
    ASSERT(x == y);
  });

  TEST(my_second_test, { ASSERT(!strcmp("hello", "bye")); });
}