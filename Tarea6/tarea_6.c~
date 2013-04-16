#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>






int main(int argc, char **argv)
{
  
  double h = atof(argv[1]);
  double o= 10;
  double p= 28.0;
  double b= 8.0/3.0;
  double x_final= 30.0;
  int n_points = (int)((x_final+h))/(h);
  double t[n_points];
  double x[n_points];
  double y[n_points];
  double z[n_points];
  double xp[n_points];
  double yp[n_points];
  double zp[n_points];
  double ci[30];
  
  
 
  t[0] = 0;
  
  aleatorios(ci);

  

  
  
  int i = 0;

  x[0]=ci[0];
  y[0]=ci[1];
  z[0]=ci[2];

  //printf("%f %f %f\n",x[0],y[0],z[0]);

  int j;
  
  for(j=0;j<10;j++)
  {
  	x[0]=ci[j*3];
    y[0]=ci[j*3+1];
    z[0]=ci[j*3+2];
    
    char buffer[10];
	int i = j;
	snprintf(buffer, 10,"%d",i);
    
    char* cadena = strcat(buffer,".dat");
 
    RK4(t,x,y,z,h,n_points,o,p,b,cadena);   
  }

  
  
  
  return 0;
}



