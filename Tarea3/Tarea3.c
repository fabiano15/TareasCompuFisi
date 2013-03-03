#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#define USAGE "./a.out nombre.txt"
void load_file(char*);
void guardar_datos(float*,char*, int);
float* crear_matriz(float*,int);
void print_matrix(float*, int, int);
float* transpose(float*, int, int);

int main(int argc, char **argv){
	
	FILE *in;
	int filas;
	char *filename=argv[1];
	float *vector_datos;
	float *matriz;
	float *matriz_transpuesta;
	
	
	if(argc!=2){
   	 	printf("USAGE: %s\n", USAGE);
   	 	exit(1);
  	}
	
	
	load_file(filename);
	
	filas=contar_filas(filename);

	vector_datos=malloc(2*filas*sizeof(float));
	
	guardar_datos(vector_datos,filename,filas);

	matriz=crear_matriz(vector_datos,filas);
	printf("\n");
	
	matriz_transpuesta=transpose(matriz, filas,3);
	
	
}




//////////////////////////////////////////METODOS//////////////////////////////////////////////////

/////////////////////LOAD_FILE/////////////////////////
void load_file(char *filename){
	FILE *in;
	
  	
  	in = fopen(filename,"r"); 
  	
  	if(!in){
    	printf("problem opening the file %s\n", filename);
    	exit(1);
 	} 
 	
 	printf("el archivo obtenido es: %s \n",filename);
}

/////////////////////CONTAR_FILAS/////////////////////////

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

/////////////////////GUARDAR_DATOS/////////////////////////

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

/////////////////////CREAR_MATRIZ/////////////////////////

float* crear_matriz(float *vector, int filas)
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
		I[i*n_y]=1;
		I[i*n_y+1]=vector[2*i];
		I[i*n_y+2]=(vector[2*i+1]*vector[2*i+1])/2;
      
		
      
    }
  }

  print_matrix(I,n_x,n_y);
  
  return I;
}

/////////////////////TRANSPOSE/////////////////////////

float* transpose(float *m, int n_x, int n_y){
	
	/*int i,j,pos_ij, pos_ji,diferencia;
	float tmp;
	diferencia=n_x-n_y; 

	for(i=0;i<n_x;i++){
		for(j=i;j<n_y;j++){
		pos_ij = i + (n_y * j);
		pos_ji = j + (n_y * i);

		tmp = m[pos_ij];
		m[pos_ij] = m[pos_ji];
		m[pos_ji] = tmp;      
		}
	  }
	  
	  print_matrix(m, n_y, n_x);
	  
	  return m;
	
	gsl_matrix_transpose_memcpy (gsl_matrix * m, const gsl_matrix * salida);
	print_matrix(salida, n_y, n_x);
*/}

/////////////////////PRINT_MATRIX/////////////////////////

void print_matrix(float *I, int n_x, int n_y){
	int i;
	int j;
	int pos;
	for(i=0;i<n_x;i++){
		for(j=0;j<n_y;j++){
		 	pos = j + (n_y * i);/*position in the array*/
		fprintf(stdout, " %f ",I[pos]);
		}
		fprintf(stdout, "\n");
  	}
}

