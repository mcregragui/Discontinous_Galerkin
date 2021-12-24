#include "include/InitCondition.h"


double u0(double x)
{
    if (x<L/4)
    {
        return cos(x);
    }
    if (x>=L/4 && x<L/2)
    {
        return cos(x)+0.3;
    }
    else
    {
        return cos(x)+0.6;
    }
    //return cos(x);
}

std::vector<double> Vect0()
{
    std::vector<double> sol(ord*std::floor(L/dx),0);
     
    for(int i=0;i<std::floor(L/dx);i++)
    {
        sol[ord*i]=u0(i*dx);
    }
    return sol;
}

std::vector<double>  vectp(int n)
{
    std::vector<double> sol(std::floor(L/dx),0);
     
    for(int i=0;i<std::floor(L/dx);i++)
    {
        sol[i]=u0(i*dx-adv*dt*n);
    }
    return sol;
}

std::vector<double> transformp(std::vector<double> U,double x)
{
    std::vector<double> sol(std::floor(L/dx),0);
     
    for(int i=0;i<std::floor(L/dx);i++)
    {
        
        
        if(ord==1)
        {
            sol[i]=U[ord*i];
        }
        if(ord==2)
        {
            sol[i]=U[ord*i]+coeff(1)*U[ord*i+1]*legendre(1,i,x);
        }
        if(ord==3)
        {
            sol[i]=U[ord*i]+coeff(1)*U[ord*i+1]*legendre(1,i,x)+coeff(2)*U[ord*i+2]*legendre(2,i,x);
        }
    }
    return sol;
}