#include <stdio.h>

int main () {
  int num;
  puts("Input a integer number from 1 to 3");
  scanf("%d", &num);

  // On this code, it will show any message under the case coincidense prompt 
  
  switch(num) {
    case 3 : 
      puts("Message on case 3"); 
    case 2 : 
      puts("Message on case 2"); 
    case 1 : 
      puts("Message on case 1"); 
  }

  return 0;
}
