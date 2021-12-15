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

int clear_buffer(char *flag, int *argc, int *last_arg); // is there really a need for this function?

int main(int argc, char *argv[]) {
  unsigned int word_count = 0;
  unsigned int new_lines = 0;
  unsigned int num_of_letters = 0;
  int last_arg = argc - 1;
  char *last_arg_val;
<<<<<<< HEAD
  // seems to me that 2 bytes is all you need, especially if you are going to be iterating on them
  char data[2] = "\0";
=======
  // seems to me that 2 bits is all you need, especially if you are going to be iterating on them
  // made size of char variable, because it is system dependent
  char *data = malloc(2 * sizeof(char));
>>>>>>> bb26e81 (changed the malloc for char* data)
  last_arg_val = argv[last_arg];
  int use = clear_buffer(last_arg_val, &argc, &last_arg);

  for (int i = 1; i < argc; i++) {

    if (use == 0) {
      system(CMD);
    }

    FILE *input = fopen(argv[i], "r");

    if (input == NULL) {
      printf("pussy: %s: No such file or directory\n", argv[i]);
      return 1;
    }

    // instead of having to iterate over 50 characters to do our check, we just do 2, decreasing the number of nested iterations
    while ((fgets(data, 2, input)) != NULL) {

      printf("%c", *data);
      word_count++;

      // if the character contains carriage return, increment
      // was broken, changed this from c --> data
      if (*data == '\n')
        new_lines++;
    }
    free(data); // free the malloc on *data after final ouptput
  }

  num_of_letters = word_count - 1 - (new_lines - 1);

  // just a bit cleaner imo; if we submit no input, we already know there are 0 letters
  if (word_count != 0){

    // might want to consider making this an optional flag, because when you pipe it or >> into a file, it prints that along with the input
    printf("\nletters = %d\n", num_of_letters);
  }

  return 0;
}

int clear_buffer(char *flag, int *argc, int *last_arg) {
  if (strcmp(flag, "-c") == 0) {
    *argc = *last_arg;
    free(flag);

    return 0;
  }

  return 1;
}
