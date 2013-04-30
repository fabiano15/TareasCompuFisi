#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>





int main(int argc, char **argv)
{
  
  int n_points = 100;
  //double h = atof(argv[1]);
  //double o= 10;
  //double p= 28.0;
  //double b= 8.0/3.0;
  
  
  double x_min= -5.0;
  double x_max= 5.0;
  double t[n_points];
  double x[n_points];
  double uini[n_points];
  double uini2[n_points];
  double ufin[n_points];
  double deltax = (x_max-x_min)/n_points;
  double deltat = 0.0003;
  double alfa = deltat/(deltax*deltax);

  //double y[n_points];
  //double z[n_points];
  //double xp[n_points];
  //double yp[n_points];
  //double zp[n_points];
  //double ci[30];
  int i = 0;
  
  for(i=0;i<n_points;i++)
  {
  	  if(i==0)
  	  {
  	     x[i] = -5; 
  	  }
  	  else
  	  {
  	     x[i] = x[i-1] + deltax;
  	   	  
  	  }
  
  }
  
  llenaruini(x,uini,uini2,n_points);
  
  llenarufin(alfa,uini,ufin,x,n_points);
  
  /*
  //print
  for(i=0;i<n_points;i++)
  {
  	  printf("%f %f\n",uini[i],x[i]);
  
  }
 */
  //escribir_archivo("0.dat",x,ufin,n_points);
  
  //aleatorios(ci);

  

  
 /*

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

  
  */
  
  return 0;
}



