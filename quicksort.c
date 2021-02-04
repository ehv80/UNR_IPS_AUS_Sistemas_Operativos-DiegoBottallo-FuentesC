#include <stdio.h>

/************************** VARIABLES GLOBALES ***************************/
unsigned int tamanio;
int arreglo[];

/********************** PROTOTIPOS ******************************/
void intercambia( int arreglo[] , int i , int j ); 
void quicksort( int arreglo[] , int inicial, int final ); 
void inicializa( int arreglo[] );
void exibe( int arreglo[] );


/********************** FUNCIONES *******************************/
void intercambia( int arreglo[] , int i , int j )
{
	int temp   = arreglo[i];
	arreglo[i] = arreglo[j];
	arreglo[j] = temp;
}

void quicksort( int arreglo[] , int inicial, int final )
{
	int i, ultimo; //indice del último elemento del subarreglo izquierdo de menores
	if( inicial >= final ) return;	// se ha recorrido todo el arreglo
	
	intercambia( arreglo , inicial , (inicial + final)/2 ); 
	// pivote es arreglo[(inicial + final)/2], lo pone al principio
	
	ultimo = inicial;

	// partición
	for( i = inicial + 1 ; i <= final ; i++ )
	{
		if( arreglo[i] < arreglo[inicial] )
			intercambia( arreglo , ++ultimo , i);
	}
	
	intercambia( arreglo , inicial , ultimo ); 
	// ubica pivote a la derecha del subarreglo izquierdo de menores
	
	quicksort( arreglo , inicial , ultimo - 1 ); // aplica quicksort al subarreglo izquierdo de menores
	quicksort( arreglo , ultimo + 1 , final );   // aplica quicksort al subarreglo derecho   de mayores
}

void inicializa( int arreglo[] )
{
	printf("\n INTRODUZCA VALORES ENTEROS PARA LOS ELEMENTOS DEL ARREGLO: \n");
	int i;
	for( i=0 ; i < tamanio ; i++)
	{
		printf(" 	ARREGLO[%d] : ", i);
		scanf( "%d" , &( arreglo[i] ) );
		printf("\n");
	}
}

void exibe( int arreglo[] )
{
	printf("\n");
	int i;
	for( i=0 ; i < tamanio ; i++ )
	{
		printf("	ARREGLO[%d] = %d \n" , i , arreglo[i] );
	}
	printf("\n");
}

/******************************** FUNCIÓN PRINCIPAL MAIN *********************************/
int main()
{
	printf("\n INGRESE LA CANTIDAD DE ENTEROS QUE CONTENDRÁ EL ARREGLO: ");
	scanf( "%d" , &tamanio );
	inicializa( arreglo );
	printf("\n	ESTADO ACTUAL EN QUE SE ENCUENTRA EL ARREGLO: \n");
	exibe( arreglo );
	printf("\n······APLICANDO EL METODO DE ORDENACIÓN QUICKSORT AL ARREGLO······\n");
	quicksort( arreglo , 0 , tamanio - 1);
	printf("\n	 EL ARREGLO ORDENADO MEDIANTE QUICKSORT: \n");
	exibe( arreglo );
	return 0;	// devuelve señal de terminación exitosa del proceso al entorno
}
