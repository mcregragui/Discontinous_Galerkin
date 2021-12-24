#include "include/Quadrature.h"


std::vector<double> FU(std::vector<double>& U)
{
    return adv*U;
}

std::vector<double> Quadrature(std::vector<double>& sol)
{
    std::vector<double> solh(std::floor(L/dx),0);
    std::vector<double> temp1(std::floor(L/dx),0),temp2(std::floor(L/dx),0),temp3(std::floor(L/dx),0);
    std::vector<double> Q(ord*std::floor(L/dx),0);
    for(int j=0;j<std::floor(L/dx);j++)
    {
        Q[ord*j]=0.0;

        if(ord>1)
        {
            Q[ord*j+1]=(adv/(2*dx))*((5.0/9.0)*transformp(sol,dx*(j-0.5*sqrt(3.0/5.0)))[j]+(5.0/9.0)*transformp(sol,dx*(j+0.5*sqrt(3.0/5.0)))[j]+(8.0/9.0)*transformp(sol,dx*j)[j]);

        }
        if(ord==3)
        {
            Q[ord*j+2]=(adv/(dx*dx*dx))*((5.0/9.0)*transformp(sol,dx*(j-0.5*sqrt(3.0/5.0)))[j]*legendre(1,j,dx*(j-0.5*sqrt(3.0/5.0)))+(5.0/9.0)*transformp(sol,dx*(j+0.5*sqrt(3.0/5.0)))[j]*legendre(1,j,dx*(j+0.5*sqrt(3.0/5.0)))+(8.0/9.0)*transformp(sol,dx*j)[j]*legendre(1,j,dx*j));

        }

    }
    return Q;
}


std::vector<double> Quadrature0()
{
    std::vector<double> Q(ord*std::floor(L/dx),0);
    for(int j=0;j<std::floor(L/dx);j++)
    {
        Q[ord*j]=(0.5)*((5.0/9.0)*u0(dx*(j-0.5*sqrt(3.0/5.0)))+(5.0/9.0)*u0(dx*(j+0.5*sqrt(3.0/5.0)))+(8.0/9.0)*u0(dx*j));

        if(ord>1)
        {
            Q[ord*j+1]=(0.5/dx)*((5.0/9.0)*u0(dx*(j-0.5*sqrt(3.0/5.0)))*legendre(1,j,dx*(j-0.5*sqrt(3.0/5.0)))+(5.0/9.0)*u0(dx*(j+0.5*sqrt(3.0/5.0)))*legendre(1,j,dx*(j+0.5*sqrt(3.0/5.0)))+(8.0/9.0)*u0(dx*j)*legendre(1,j,dx*j));
        }
        if(ord==3)
        {
            Q[ord*j+2]=(0.5/(dx*dx))*((5.0/9.0)*u0(dx*(j-0.5*sqrt(3.0/5.0)))*legendre(2,j,dx*(j-0.5*sqrt(3.0/5.0)))+(5.0/9.0)*u0(dx*(j+0.5*sqrt(3.0/5.0)))*legendre(2,j,dx*(j+0.5*sqrt(3.0/5.0)))+(8.0/9.0)*u0(dx*j)*legendre(2,j,dx*j));
        }
        
    }
    return Q;
}