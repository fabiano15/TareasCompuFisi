#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>



double u_inicial(double x)
{
  return 4*x-4*x*x;
}




void aleatorios(double* ci)
{

	srand48(time(NULL));

	int i;
	for(i=0;i<30;i++)
	 	{
	 	ci[i] = drand48()*20-10;
	 	}

}

void llenaruini(double* x, double* uini, double* uini2, int n_points)
{
	int i =0;
	uini[0]=0.0;
	uini[n_points-1] = 0.0;
	uini2[0]=0.0;
	uini2[n_points-1] = 0.0;
	for(i=1;i<n_points-1;i++)
	{
		
		uini[i] = u_inicial(x[i]);
		uini2[i] = u_inicial(x[i]);
	}
	

}
void escribir_archivo(char* nombre_archivo, double* x, double* u,int n_points)
{
	FILE* in;
	int i;
	in=fopen(nombre_archivo, "w");
	
	for(i=0;i<n_points;i++)
	{
		fprintf(in,"%f %f \n",x[i],u[i]);
	}
	
	
}



void llenarufin(double alfa, double* uini, double* ufin, double* x, int n_points)
{
	int i = 0;
	int j = 0;
	int tiempo = 10001;
	
	ufin[0] = 0.0;
	ufin[n_points-1] = 0.0; 
	
	double utemp1[n_points];
	double utemp2[n_points];
	
	for(j=0;j<tiempo;j++)
	{
		
		for(i=1; i<n_points-1;i++)
		{
			ufin[i] = alfa*uini[i+1] + (1-2*alfa)*uini[i] + alfa*uini[i-1];
			
		}
		for(i=1; i<n_points-1;i++)
		{
			uini[i] = ufin[i];
			
		}
		
		if(j%1000==0)
		{
			char buffer[10];
			snprintf(buffer, 10,"%d",j);
   		    char* cadena = strcat(buffer,".dat");
		    escribir_archivo(cadena,x,uini,n_points);
		}
	
		
	}
	
	



}



/*
void RK(double* t, double* x, double* y,  double* z ,double h,int n_points, double o, double p, double b, char* nombre_archivo)
{
int i;
for(i=0; i<n_points;i++)
  {
    double x_prime = func_xp(x[i],y[i],z[i],o);
    double y_prime = func_yp(x[i],y[i],z[i],p);
    double z_prime = func_zp(x[i],y[i],z[i],b);

    double t_middle = t[i] + (h/2.0);
    double x_middle = x[i] + (h/2.0) * x_prime;
    double y_middle = y[i] + (h/2.0) * y_prime;
    double z_middle = z[i] + (h/2.0) * z_prime;
    

    double x_middle_prime = func_xp(x_middle, y_middle, z_middle, o);
    double y_middle_prime = func_yp(x_middle, y_middle, z_middle, p);
    double z_middle_prime = func_zp(x_middle, y_middle, z_middle, b);

    t[i+1] = t[i] + h;
    x[i+1] = x[i] + h * x_middle_prime ;
    y[i+1] = y[i] + h * y_middle_prime ;
    z[i+1] = z[i] + h * z_middle_prime ;

   printf("%f %f %f %f\n",t[i],x[i], y[i], z[i]);
  }
	escribir_archivo(nombre_archivo,t,x,y,z,n_points);
}


void RK4(double* t, double* x, double* y,  double* z ,double h,int n_points, double o, double p, double b, char* nombre_archivo)
{
int i;
for(i=0; i<n_points;i++)
  {
    double x_prime = func_xp(x[i],y[i],z[i],o);
    double y_prime = func_yp(x[i],y[i],z[i],p);
    double z_prime = func_zp(x[i],y[i],z[i],b);


// primera iter
    double t_middle = t[i] + (h/2.0);
    double x_middle = x[i] + (h/2.0) * x_prime;
    double y_middle = y[i] + (h/2.0) * y_prime;
    double z_middle = z[i] + (h/2.0) * z_prime;
    

    double x_prime2 = func_xp(x_middle, y_middle, z_middle, o);
    double y_prime2 = func_yp(x_middle, y_middle, z_middle, p);
    double z_prime2 = func_zp(x_middle, y_middle, z_middle, b);
    
    
    // segunda iter
    
    double t_middle2 = t[i] + (h/2.0);
    double x_middle2 = x[i] + (h/2.0) * x_prime2;
    double y_middle2 = y[i] + (h/2.0) * y_prime2;
    double z_middle2 = z[i] + (h/2.0) * z_prime2;
    
    double x_prime3 = func_xp(x_middle2, y_middle2, z_middle2, o);
    double y_prime3 = func_yp(x_middle2, y_middle2, z_middle2, p);
    double z_prime3 = func_zp(x_middle2, y_middle2, z_middle2, b);
    
    
    // terc eriter
    
    double t_middle3 = t[i] + (h/2.0);
    double x_middle3 = x[i] + (h/2.0) * x_prime3;
    double y_middle3 = y[i] + (h/2.0) * y_prime3;
    double z_middle3 = z[i] + (h/2.0) * z_prime3;
    
    double x_prime4 = func_xp(x_middle3, y_middle3, z_middle3, o);
    double y_prime4 = func_yp(x_middle3, y_middle3, z_middle3, p);
    double z_prime4 = func_zp(x_middle3, y_middle3, z_middle3, b);
    
 //cuarto

	double averageX=(1.0/6.0)*(x_prime+2.0*x_prime2+2.0*x_prime3+x_prime4);
	
	double averageY=(1.0/6.0)*(y_prime+2.0*y_prime2+2.0*y_prime3+y_prime4);
	
	double averageZ=(1.0/6.0)*(z_prime+2.0*z_prime2+2.0*z_prime3+z_prime4);

    t[i+1] = t[i] + h;
    x[i+1] = x[i] + h * averageX ;
    y[i+1] = y[i] + h * averageY ;
    z[i+1] = z[i] + h * averageZ ;

  // printf("%f %f %f %f\n",t[i],x[i], y[i], z[i]);
  }
	escribir_archivo(nombre_archivo,t,x,y,z,n_points);
	
	
	
	
	
	
}*/
