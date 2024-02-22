#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

char **parseEnvVar(const char *envVar, size_t *valuesSize) {
  const char *cur_ch = envVar;

  char **values = NULL;
  size_t size = strlen(envVar);

  values = (char **)malloc(size * sizeof(char *));
  if (values == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  while (*cur_ch != '\0') {
    size_t ts_size = 0;
    size_t temp_size = 10;
    char *temp_string = (char *)malloc(temp_size * sizeof(char));

    if (temp_string == NULL) {
      fprintf(stderr, "Memory allocation failed.\n");
      exit(EXIT_FAILURE);
    }

    while (isalpha(*cur_ch) || isdigit(*cur_ch)) {
      temp_string[ts_size] = *cur_ch;
      ts_size++;
      cur_ch++;

      // Resize temp_string if needed
      if (ts_size >= temp_size) {
        temp_size *= 2; // Double the size
        temp_string = realloc(temp_string, temp_size * sizeof(char));

        if (temp_string == NULL) {
          fprintf(stderr, "Memory allocation failed.\n");
          exit(EXIT_FAILURE);
        }
      }
    }

    // Allocate just enough memory for the string
    values[*valuesSize] = (char *)malloc((ts_size + 1) * sizeof(char));

    if (values[*valuesSize] == NULL) {
      fprintf(stderr, "Memory allocation failed.\n");
      exit(EXIT_FAILURE);
    }

    // Copy the string to the allocated memory
    strncpy(values[*valuesSize], temp_string, ts_size);
    values[*valuesSize][ts_size] = '\0'; // Null-terminate the string
    (*valuesSize)++;

    // Free the temporary string
    free(temp_string);

    // Move to the next non-alphabetic character
    while (*cur_ch != '\0' && !isalpha(*cur_ch)) {
      cur_ch++;
    }
  }

  return values;
}