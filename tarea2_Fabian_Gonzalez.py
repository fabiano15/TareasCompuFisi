# -*- coding: latin-1 -*-
import sys, string, os

archivo = sys.argv[1];

frecuencias= [0]*200
caracteres = [""]*200
caracter =[""]*15
contador_total=0
k=0;

caracter[0]=" "
caracter[1]="\n"
caracter[2]="."
caracter[3]=","
caracter[4]=":"
caracter[5]=";"
caracter[6]="!"
caracter[7]="?"
caracter[8]="¿"
caracter[9]="¡"
caracter[10]="("
caracter[11]=")"
caracter[12]=" )"
caracter[13]=chr(13)
caracter[14]="'"

def caracter_nuevo(nuevo):
	i=0
	termino = 0
	for x in caracteres:
		if(caracteres[i] == "" and termino == 0 and buscar_caracter(nuevo)!=1):
		
				caracteres[i] = nuevo
				frecuencias[i] = 1
				termino = 1
		i=i+1

def buscar_caracter(caracter_nuevo):
	for caracterr in caracter:
		if (caracter_nuevo==caracterr):
			return 1
	return 0

def agregar_caracteres(linea):
	encontro = 0;
	for caracter1 in linea:
		jj=0
		for caracter2 in caracteres:
			if(caracter1 == caracter2):
					frecuencias[jj] = frecuencias[jj]+1
					encontro = 1
					jj=jj+1	
			jj=jj+1
					
					
		if(encontro == 0):
			caracter_nuevo(caracter1)
		encontro=0
					
						
def contar_total_caracteres():
	contador=0
	jj=0;
	for j in frecuencias:
		contador=contador+frecuencias[jj]
		jj=jj+1;
	return contador
		
def sacar_porcentaje(contador_total):
	ii=0
	

	for i in frecuencias:
		frecuencias[ii]=float(frecuencias[ii])*100/contador_total
		

		ii=ii+1
	



# read the file
infile = open(archivo, 'r')

for line in infile:
    agregar_caracteres(line)

        
contador_total=contar_total_caracteres()


sacar_porcentaje(contador_total)

matriz = [frecuencias,caracteres]


from operator import itemgetter
inv = zip(*matriz)
inv.sort(reverse = 1,key=itemgetter(0))
matriz = zip(*inv)


final = open("frecuencias_"+archivo,"w")



for frecuencia in frecuencias:
		parte1=matriz[0][k]
		parte2=matriz[1][k]
		
		parte1 = str(parte1)
		
		value = parte2 +"                  "+ parte1 +"%" + "\n"
		
		if(parte2 != ""):
				final.write(value)
		k = k+1
		
		
