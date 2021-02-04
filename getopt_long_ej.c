#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

char* prog_name;

void print_usage(FILE* stream, int exit_code) {
   fprintf(stream,
           "Usage: %s <option> <op1> <op2> [-o filename]\n\n", prog_name);
   fprintf(stream,
	   "  -s  --suma              Suma op1 y op2.\n"
	   "  -r  --resta             Resta op2 a op1.\n"
	   "  -p  --producto          Multiplica op1 op2 veces.\n"
	   "  -c  --cociente          Divide op1 por op2.\n"
	   "  -o  --output filename   Coloca el resultado en filename.\n");
   exit(exit_code);
}

int main (int argc, char** argv) {
   int next_opt;
   int op1, op2, result;
   char last_op;
   FILE* fd = NULL; /*para opcion -o --output*/
   
   /*Opciones cortas*/
   char* short_options = "srpco:";
   /*Opciones largas*/
   struct option long_options[] = {
      {"suma", 0, NULL, 's'},
      {"resta", 0, NULL, 'r'},
      {"producto", 0, NULL, 'p'},
      {"cociente", 0, NULL, 'c'},
      {"output", 1, NULL, 'o'},
      {NULL, 0, NULL, 0}
   };
   prog_name = argv[0];

   if (argc < 4 || argc > 6)
      print_usage(stderr, 1);

   op1 = atoi(argv[2]);
   op2 = atoi(argv[3]);
	
   do {
      next_opt = getopt_long(argc, argv,
		             short_options,
			     long_options, NULL);

      switch(next_opt) {
         case 's':
	    printf("La suma es: %d\n", result=op1+op2);
	    last_op = 's';
	    break;
         case 'r':
	    printf("La resta es: %d\n", result=op1-op2);
	    last_op = 'r';
	    break;
         case 'p':
	    printf("El producto es: %d\n", result=op1*op2);
	    last_op = 'p';
	    break;
         case 'c':
	    op2 ? printf("El cociente es: %d\n", result=op1/op2)
		: (printf("Error. Division por cero\n"), exit(2));
	    last_op = 'c';
	    break;
	 case 'o':
	    fd = fopen(optarg, "w");
	    switch(last_op) {
	       case 's': fprintf(fd, "Suma= %d", result);      break;
	       case 'r': fprintf(fd, "Resta= %d", result);     break;
	       case 'p': fprintf(fd, "Producto= %d", result);  break;
	       case 'c': fprintf(fd, "Cociente= %d", result);  break;
	    }
	    fclose(fd);
	    exit(0);
	    break;
	 case '?':
	    print_usage(stderr, 1);
	 default:
	    abort(); /*Error inesperado*/
      }
   } while(next_opt != -1);

   return 0;
}
