#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Use: %s param1 param2 ... \n", argv[0]);
    return 1;
  }
  printf("Number of arguments: %d\n", argc - 1);
  printf("Arguments:\n");
  for (int i=1; i < argc; i++){
    printf("%s\n", argv[i]);
  }
  return 0;
}