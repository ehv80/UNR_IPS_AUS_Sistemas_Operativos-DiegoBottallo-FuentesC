/*MACROS ASSERT*/
#include <stdio.h>

#define A(x) x     /* notar la diferencia entre A y B!!*/
#define B(x) #x    /* el operador # "stringiza" o "cadeniza",
		      palabras inventadas ;-)*/

#define P(x,y) xy    /*retorna el simbolo xy, no respeta los argumentos*/
#define Q(x,y) x##y  /*pasting: respeta los argumentos*/

int main () {   
   int hola = 500;
   int xy = 9; 

   printf("%d\n", A(2<4)); /*Imprime 1, es decir "verdadero"*/   
   //printf("%s\n", A(2<4)); /*Error, al menos un warning*/
   printf("%s\n", B(2<4)); /*Imprime la cadena: "2<4"*/   
   printf("%d\n", P(ho,la)); /*Imprime el valor de la variable xy, no hola!*/   
   printf("%d\n", Q(ho,la)); /*Imprime el valor de la variable hola*/   
   
   return 0;
}



