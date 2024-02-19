#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  const char *envVar = getenv("SURTUR_TEST");
  size_t valuesSize = 0;
  char **values = parseEnvVar(envVar, &valuesSize);
  // Print the values

  for (size_t i = 0; i < valuesSize; i++) {
    printf("value: %s\n", values[i]);
  }

  // Free the values array
  for (size_t i = 0; i < valuesSize; i++) {
    free(values[i]);
  }
  free(values);

  return 0;
}