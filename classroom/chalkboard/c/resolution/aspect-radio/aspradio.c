#include <stdio.h>
#include <stdlib.h>

int* aspectRadio(int, int);

int main (int argsc, char* argsv[]) {
   int width = atoi(argsv[1]);
   int height = atoi(argsv[2]);
   int a = 1;
   int rel = height;
   while (a) {
     if ((width % rel) == 0) {
       if ((height % rel) == 0) {
      
          printf("%d:%d",
             width/rel,
             height/rel);
          a = 0;
       }       
     }
     rel --;
   }   
}

