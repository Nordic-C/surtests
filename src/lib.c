#include "parser.h"
#include "tests.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char* envVar = getenv("SURTUR_TESTS");

  if (envVar == NULL) {
    fprintf(stderr, "Failed to get SURTUR_TEST env var\n");
    exit(EXIT_FAILURE);
  }
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
}
