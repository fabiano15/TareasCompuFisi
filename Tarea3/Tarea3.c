#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define USAGE "./a.out nombre.txt"
void load_file(char*);
void guardar_datos(float*,char*, int);
void crear_matriz();
int main(int argc, char **argv){
	
	FILE *in;
	int filas;
	char *filename=argv[1];
	float *vector_datos;
	
	if(argc!=2){
   	 	printf("USAGE: %s\n", USAGE);
   	 	exit(1);
  	}
	
	
	load_file(filename);
	
	filas=contar_filas(filename);

	vector_datos=malloc(2*filas*sizeof(float));
	
	guardar_datos(vector_datos,filename,filas);
	printf("vector en la posicion 5 es:%f\n",vector_datos[5]);
	crear_matriz(vector_datos,filas);
}


void load_file(char *filename){
	FILE *in;
	
  	
  	in = fopen(filename,"r"); 
  	
  	if(!in){
    	printf("problem opening the file %s\n", filename);
    	exit(1);
 	} 
 	
 	printf("el archivo obtenido es: %s \n",filename);
}


int contar_filas(char *filename)
{
	FILE *in;
	int contador=0;
	int c;
	
	if(!(in=fopen(filename, "r"))){
    printf("problem opening file %s\n", filename);
    exit(1);
 	}
 	
 	
 	
	do{
    c = fgetc(in);

    if(c=='\n'){
    	contador++;

    }  

  	}while(c!=EOF);
	
	fclose(in);
	return contador;
}

void guardar_datos(float *vector,char *filename, int filas)
{
	FILE *in;
	int i;
	
	if(!(in=fopen(filename, "r"))){
    printf("problem opening file %s\n", filename);
    exit(1);
 	}
 	
 	for(i=0;i<2*filas;i++)
 	{
 		fscanf(in,"%f %f", &(vector[i*2]),&(vector[i*2+1]));
 	}
}




void crear_matriz(float *vector, int filas)
{
  float *I;
  int n_x=filas;
  int n_y=3;
  int pos;
  int i,j;

  if(!(I = malloc(sizeof(float)*n_x *n_y))){
      fprintf(stderr, "Problem with memory allocation");
      exit(1);
  }

  /*Initialization*/
  for(i=0;i<n_x;i++){
    for(j=0;j<n_y;j++){
      	pos = j + (n_y * i) ;/*position in the array*/	
		I[i*3]=1;
		I[i*3+1]=vector[2*i];
		I[i*3+2]=(vector[2*i+1]*vector[2*i+1])/2;
      
		
      
    }
  }

  /*Prints to screen*/
  for(i=0;i<n_x;i++){
    for(j=0;j<n_y;j++){
      pos = j + (n_y * i);/*position in the array*/
	fprintf(stdout, " %f ",I[pos]);
    }
    fprintf(stdout, "\n");
  }
  
  
}

