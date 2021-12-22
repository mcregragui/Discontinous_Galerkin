#include "include/SpaceScheme.h"

double Numeric_flux(double a, double b,int j,int c,char flux)
{
    if(c>0)
    {
        double a=sol[ord*j];
        double b=sol[ord*(j+1)];

        return Flux(flux,a+left(j),b-wright(j+1));
    }
    if(c<0)
    {
        double a=sol[ord*(j-1)];
        double b=sol[ord*(j)];

        return Flux(flux,a+left(j),b-wright(j+1));
    }
}

