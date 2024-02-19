#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  const char tests[] = "addingdeeznuts,b,c";
  const char *cur_ch = tests;

  char **values = NULL;
  size_t size = sizeof(tests) / sizeof(tests[0]) - 1;
  size_t cur_size = 0;

  values = (char **)malloc(size * sizeof(char *));
  if (values == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  while (*cur_ch != '\0') {
    size_t ts_size = 0;
    size_t temp_size = 10; // Initial size
    char *temp_string = (char *)malloc(temp_size * sizeof(char));

    if (temp_string == NULL) {
      fprintf(stderr, "Memory allocation failed.\n");
      exit(EXIT_FAILURE);
    }

    while (isalpha(*cur_ch)) {
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
    values[cur_size] = (char *)malloc((ts_size + 1) * sizeof(char));

    if (values[cur_size] == NULL) {
      fprintf(stderr, "Memory allocation failed.\n");
      exit(EXIT_FAILURE);
    }

    // Copy the string to the allocated memory
    strncpy(values[cur_size], temp_string, ts_size);
    values[cur_size][ts_size] = '\0'; // Null-terminate the string
    cur_size++;

    // Free the temporary string
    free(temp_string);

    // Move to the next non-alphabetic character
    while (*cur_ch != '\0' && !isalpha(*cur_ch)) {
      cur_ch++;
    }
  }

  // Print the values
  for (size_t i = 0; i < cur_size; i++) {
    printf("value: %s\n", values[i]);
    free(values[i]);
  }

  // Free the values array
  free(values);

  return 0;
}