#include "include/InitCondition.h"


double u0(double x)
{
    if (x<L/4)
    {
        return 1.0;
    }
    if (x>=L/4 && x<L/2)
    {
        return 4.0;
    }
    else
    {
        return 3.0;
    }
    //return cos(x);
}

std::vector<double> Vect0()
{
    std::vector<double> sol(ord*std::floor(L/dx),0);
     
    for(int i=0;i<ord*std::floor(L/dx);i++)
    {
        sol[i]=u0(i*dx);
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

std::vector<double> transformp(std::vector<double> U)
{
    std::vector<double> sol(std::floor(L/dx),0);
     
    for(int i=0;i<std::floor(L/dx);i++)
    {
        sol[i]=coeff(0)*U[ord*i]+coeff(1)*U[ord*i+1]*legendre(1,i,dx*i)+coeff(2)*U[ord*i+2]*legendre(2,i,dx*i);
    }
    return sol;
}