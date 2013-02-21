/*
  First writes the months of the year and its 
  corresponding number  of days to a file. 

  Afterwards it reads the same file and prints out 
  its contents to the screen.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define USAGE "./a.out contacto_de_NombreApellido.txt dia mes anio"
#define Enero 0
#define Febrero 31
#define Marzo 59
#define Abril 90
#define Mayo 120
#define Junio 151
#define Julio 181
#define Agosto 212
#define Septiembre 243
#define Octubre 273
#define Noviembre 304
#define Diciembre 334
void escribir_carta(char*,char[100][256],int);
int main(int argc, char **argv){


  FILE *in;
  int i;
  int j;
  char name[256];
  int n_days;
  int var;
  int test;
  int n_lines;
  int c;
  int numero_palabras;
  int contador;
  char *filename=argv[1];
  
  char resultado[100];
  int numero_de_linea;
  int numero_total_palabras;


	
	if(argc!=5){
   	 printf("USAGE: %s\n", USAGE);
   	 exit(1);
  	}
 
  	

	
  /*opens the file, reads, closes the file*/
  in = fopen(filename,"r"); 
  if(!in){
    printf("problem opening the file %s\n", filename);
    exit(1);
  	numero_total_palabras=0;
  } 
  
  	contador=0;
 	numero_total_palabras=contar_total_palabras(filename);
    

    
    char cadena_palabras[numero_total_palabras+4][256];
  	
  	
  	
    
    
    for(i=0;i<4;i++){
    
    	numero_palabras=contar_palabras_por_linea(filename,i);
    	
    	if(i==3){
    		fgets(resultado,256,in);
    		//printf("En la linea %d se encuentra la frase: \n %s \n",i,resultado);
    		strcpy(cadena_palabras[numero_total_palabras-1],resultado);
    		
    	}
    	else{
    		for(j=0;j<numero_palabras;j++){
    			
    			fscanf(in, "%s\n", name); 
   				printf(" aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa %s \n",name);
   				strcpy(cadena_palabras[contador],name);
   				contador++;
 			}
 		}
    }
    
    strcpy(cadena_palabras[numero_total_palabras],argv[2]);
    strcpy(cadena_palabras[numero_total_palabras+1],argv[3]);
    strcpy(cadena_palabras[numero_total_palabras+2],argv[4]);
	strcpy(cadena_palabras[numero_total_palabras+3],argv[1]);


	
  	
  	escribir_carta(filename,cadena_palabras,numero_total_palabras+4);

  	fclose(in);
  
	
	
  
  return 0;
}


void escribir_carta(char *filename, char palabra[100][256],int numero_total_palabras){
	FILE *in;
	int palabras_primera_linea;
	int palabras_segunda_linea;
	int i;
	char *dia;
	char *mes;
	char *anio;
	char *nombre;
	char *apellido;
	int dias_sin_vernos;
	char *mensaje;
	char *mi_nombre;
	char *dia_actual;
	char *mes_actual;
	char *anio_actual;
	
	


  if(!(in=fopen(filename, "r"))){
    printf("problem opening file %s\n", filename);
    exit(1);
  }
	palabras_primera_linea=contar_palabras_por_linea(filename,0);
	palabras_segunda_linea=contar_palabras_por_linea(filename,1)+palabras_primera_linea;

	/*
	for (i=0;i<numero_total_palabras;i++){
		printf("las palabras encontradas fueron:%s en %d\n",palabra[i],i);
	}*/
	
	dia=malloc(2 * sizeof(char));
	mes=malloc(8 * sizeof(char));
	anio=malloc(4 * sizeof(char));
	nombre=malloc(10 * sizeof(char));
	apellido=malloc(13 * sizeof(char));
	mensaje=malloc(50 * sizeof(char));
	mi_nombre=malloc(10 * sizeof(char));
	dia_actual=malloc(2 * sizeof(char));
	mes_actual=malloc(8 * sizeof(char));
	anio_actual=malloc(4 * sizeof(char));
	
	
	
	
	
	dia=palabra[palabras_primera_linea];
	mes=palabra[palabras_primera_linea+1];
	anio=palabra[palabras_primera_linea+2];
	
	dia_actual=palabra[numero_total_palabras-4];
	mes_actual=palabra[numero_total_palabras-3];
	anio_actual=palabra[numero_total_palabras-2];
	
	fgets(nombre,256,in);
	

	
	dias_sin_vernos=calcular_dias(dia, mes, anio, dia_actual, mes_actual, anio_actual);
	
	
	mensaje=palabra[numero_total_palabras-5];
	if(dias_sin_vernos!= -1)
	{
		printf("\nBogota %s %s %s \n",dia_actual, mes_actual ,anio_actual);
		printf("Hola %s\n", nombre);
		printf("Hace unos %d dias que no te escribo, por eso quisiera aprovechar este momento para decirte algo que siempre pense en decir:\n\n%s\n",dias_sin_vernos,mensaje);
	
	
		mensaje=palabra[palabras_segunda_linea];
		anio=palabra[palabras_segunda_linea+1];
	
		printf("Espero que nos podamos ver pronto en %s siempre he querido visitar %s.\n",mensaje,anio);
	
	
	
		char *nombre_archivo=palabra[numero_total_palabras-1];

		char *holaaaa;
		char *token = strtok_r(nombre_archivo, "_",&holaaaa);
		char *hola2;
		char *token2 = strtok_r(holaaaa, "_",&hola2);
		char *hola3;
		char *token3 = strtok_r(hola2, ".",&hola3);

	
	
		printf("\nSaludos,\n%s\n",hola2);
	}
	else{
		printf("Error!!! el formato de fecha n es correcto, por favor revise si los dias estan entre 1 y 31 o el año actual es mayor que el del archivo de texto\n");
	}

}



int contar_palabras_por_linea(char *filename, int linea){
  FILE *in;
  int numero_palabras;
  int c;
  int numero_de_linea;

  if(!(in=fopen(filename, "r"))){
    printf("problem opening file %s\n", filename);
    exit(1);
  }
  
  numero_de_linea=0;
  numero_palabras = 0;
  do{
    c = fgetc(in);
    if(c==' ' || c=='\n'){
    	numero_palabras++;
    	
    	if(c=='\n' && numero_de_linea==linea){
    		return numero_palabras;
    	}
    	else if(c=='\n'){
    		numero_de_linea++;
    		numero_palabras=0;
    	}
      
    }  

    	
    
    
  }while(c!=EOF);
  
  
  
  fclose(in);
  
}



int contar_total_palabras(char *filename){

	FILE *in;
	int numero_total_palabras;
	int numero_palabras;
	int i;
	int j;
	
	numero_total_palabras=0;
	for(i=0;i<4;i++){
    
    	numero_palabras=contar_palabras_por_linea(filename,i);
    	
    	if(i==3){
    		numero_total_palabras++;
    	}
    	else{
    		
    		numero_total_palabras=numero_total_palabras+numero_palabras;
 		
 		}
 		
    }
    
    return numero_total_palabras;
}





int calcular_dias(char *dia, char *mes,char *anio,char *dia_actual,char *mes_actual, char *anio_actual){
	int diai;
	int mesi;
	int anioi;
	int dia_actuali;
	int mes_actuali;
	int anio_actuali;
	int contador_dias;
	int comparar1;
	int comparar2;
	
	diai=atoi(dia);
	anioi=atoi(anio);
	dia_actuali=atoi(dia_actual);
	anio_actuali=atoi(anio_actual);
	comparar1=0;
	comparar2=0;

	
	if (diai>31 || dia_actuali>31 || diai<1 || dia_actuali<1 || anio_actuali<anioi){
		return -1;
	}
	else{
		
		if(!strncmp(mes,"Enero", 100))
		comparar1=Enero+diai+anioi*365;
	
		if(!strncmp(mes,"Febrero", 100))
			comparar1=Febrero+diai+anioi*365;
		
		if(!strncmp(mes,"Marzo", 100))
			comparar1=Marzo+diai+anioi*365;
		
		if(!strncmp(mes,"Abril", 100))
			comparar1=Abril+diai+anioi*365;
		
		if(!strncmp(mes,"Mayo", 100))
			comparar1=Mayo+diai+anioi*365;
	
		if(!strncmp(mes,"Junio", 100))
			comparar1=Junio+diai+anioi*365;
		
		if(!strncmp(mes,"Julio", 100))
			comparar1=Julio+diai+anioi*365;
		
		if(!strncmp(mes,"Agosto", 100))
			comparar1=Agosto+diai+anioi*365;
		
		if(!strncmp(mes,"Septiembre", 100))
			comparar1=Septiembre+diai+anioi*365;
	
		if(!strncmp(mes,"Octubre", 100))
			comparar1=Octubre+diai+anioi*365;
		
		if(!strncmp(mes,"Noviembre", 100))
			comparar1=Noviembre+diai+anioi*365;
		
		if(!strncmp(mes,"Diciembre", 100))
			comparar1=Diciembre+diai+anioi*365;
		
		
		
		
		if(!strncmp(mes_actual,"Enero", 100))
			comparar2=Enero+dia_actuali+anio_actuali*365;
	
		if(!strncmp(mes_actual,"Febrero", 100))
			comparar2=Febrero+dia_actuali+anio_actuali*365;
		
		if(!strncmp(mes_actual,"Marzo", 100))
			comparar2=Marzo+dia_actuali+anio_actuali*365;
		
		if(!strncmp(mes_actual,"Abril", 100))
			comparar2=Abril+dia_actuali+anio_actuali*365;
		
		if(!strncmp(mes_actual,"Mayo", 100))
			comparar2=Mayo+dia_actuali+anio_actuali*365;
	
		if(!strncmp(mes_actual,"Junio", 100))
			comparar2=Junio+dia_actuali+anio_actuali*365;
		
		if(!strncmp(mes_actual,"Julio", 100))
			comparar2=Julio+dia_actuali+anio_actuali*365;
		
		if(!strncmp(mes_actual,"Agosto", 100))
			comparar2=Agosto+dia_actuali+anio_actuali*365;
		
		if(!strncmp(mes_actual,"Septiembre", 100))
			comparar2=Septiembre+dia_actuali+anio_actuali*365;
	
		if(!strncmp(mes_actual,"Octubre", 100))
			comparar2=Octubre+dia_actuali+anio_actuali*365;
		
		if(!strncmp(mes_actual,"Noviembre", 100))
			comparar2=Noviembre+dia_actuali+anio_actuali*365;
		
		if(!strncmp(mes_actual,"Diciembre", 100))
			comparar2=Diciembre+dia_actuali+anio_actuali*365;
		

		if(comparar2>comparar1){
		contador_dias=comparar2-comparar1;
			return contador_dias;
		}
		else{
			return -1;
		}
	}
}










