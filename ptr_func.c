/*USO DE PUNTERO A FUNCION*/
#include <stdio.h>

int f(int i) { return i*2; }
int g(int i) { return i*5; }

int main () {
   int (*ptr) (int);
   /* ptr es un puntero a una funcion que toma un int y retorna un int */ 

   printf("f(%d) = %d\n", 3, f(3));
   ptr = f;
   printf("f(%d) = %d\n", 3, ptr(3));
   ptr = g;
   printf("g(%d) = %d\n", 3, g(3));
   printf("g(%d) = %d\n", 3, ptr(3)); 
   printf("g(%d) = %d\n", 3, (*ptr)(3));  /* analogo al anterior */
   
   return 0;
}
