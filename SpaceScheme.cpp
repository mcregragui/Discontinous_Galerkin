#include "include/SpaceScheme.h"

double Numeric_flux(std::vector<double>& sol,int j,int c,int flux)
{
    double a=0.0;
    double b=0.0;
    if(c>0)
    {
        if(j==std::floor(L/dx)-1)
        {
            a=sol[ord*j];
            b=sol[ord*(j)];
            return Flux(flux,a+left(sol,j),b-wright(sol,j));
        }
        else
        {
            a=sol[ord*j];
            b=sol[ord*(j+1)];
            return Flux(flux,a+left(sol,j),b-wright(sol,j+1));
        }
        

        //return Flux(flux,a+leftMod(sol,j),b-wrightMod(sol,j+1));
    }
    if(c<0)
    {
        if(j==0)
        {
            a=sol[ord*(j)];
            b=sol[ord*(j)];
        }
        else
        {
            a=sol[ord*(j-1)];
            b=sol[ord*(j)];
        }
        

        return Flux(flux,a+leftMod(sol,j),b-wrightMod(sol,j+1));
    }
}

std::vector<double> LH(std::vector<double> sol, int flux)
{
    std::vector<double> output(sol.size());
    for(int j=0;j<std::floor(L/dx);j++)
    {
        output[ord*j]=-(1/dx)*(Numeric_flux(sol,j,1,flux)-Numeric_flux(sol,j,-1,flux));  

        
        if(ord>1)
        {
            output[ord*j+1]=-(0.5/dx)*(Numeric_flux(sol,j,1,flux)+Numeric_flux(sol,j,-1,flux))+sol[ord*j]/dx;
        }
        if(ord==3)
        {
            output[ord*j+2]=-(1/(6*dx))*(Numeric_flux(sol,j,1,flux)-Numeric_flux(sol,j,-1,flux))+2*sol[ord*j+1]/dx;
        }
    }
    return output;


}

