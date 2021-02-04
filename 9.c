#include <stdio.h>
#define MAX 32000
#define SET(i) (arr[i/8] |= (1<<(i%8)))
#define CHECK(i) (arr[i/8] & (1<<(i%8)))

char arr[MAX/8+1];

int main () {
  int nro;
	    
  printf("INGRESE LOS ELEMENTOS DEL CONJUNTO:\n");
  do {
    scanf("%d", &nro);
    SET(nro);
  } while (nro >= 0);

  printf("ELEMENTOS DEL CONJUNTO EN ORDEN ASCENDENTE:\n");
  for (nro=0; nro<=MAX; nro++)
    if (CHECK(nro)) 
      printf("%d ", nro);
			  
  return 0;
}
