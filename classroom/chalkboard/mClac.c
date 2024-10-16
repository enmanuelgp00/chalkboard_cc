#include <stdio.h>

int main() {
  for (int i = 0; i < 10; i++) {
    printf("%c", '*');
    for (int a = 0; a < i; a++) {
      if (a == i - 1) {
        printf("%c", '*');
      } else if (i == 10 - 1) {
        printf("%c", '*');
      } else {
        printf("%c", ' ');
      }
    }
    puts("");
  }
  return 0;
}
