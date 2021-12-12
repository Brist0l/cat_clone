#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
  #define CMD "cls"
#elif _WIN64
  #define CMD "cls"
#else
  #define CMD "clear"
#endif 

int clear_buffer(char *flag, int *argc, int *last_arg);

int main(int argc, char *argv[]) {
  char c;
  unsigned int word_count = 0;
  unsigned int new_lines = 0;
  unsigned int num_of_letters = 0;
  int last_arg = argc - 1;
  char *last_arg_val;
  char data[50];

  last_arg_val = argv[last_arg];
  int use = clear_buffer(last_arg_val, &argc, &last_arg);

  for (int i = 1; i < argc; i++) {
    if (use == 0) {
      system(CMD);
    }
    FILE *input = fopen(argv[i], "r");

    if (input == NULL) {
      printf("pussy: %s:No such file or directory", argv[i]);
      return 1;
    }

    while ((fgets(data, 50, input)) != NULL) {
      printf("%s", data);
      word_count++;

      if (c == '\n')
        new_lines++;
    }
  }

  num_of_letters = word_count - 1 - (new_lines - 1);

  printf("\nletters = %d\n", num_of_letters);
}

int clear_buffer(char *flag, int *argc, int *last_arg) {
  if (strcmp(flag, "-c") == 0) {
    *argc = *last_arg;
    return 0;
  }
  return 1;
}
