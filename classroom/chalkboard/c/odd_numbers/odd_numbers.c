/*
  Build a program that receives as input a positive natural number and 
  prints the natural odd numbers less than it 
*/

#include <stdio.h>
int main() {
 
  int num;
  printf("Input a positive natural number :");
  scanf("%d", &num);

  for (int i = num; i > 0; i-- ) {
    if (i % 2 != 0) printf("%d \n", i);
  }
  return 0;
}
