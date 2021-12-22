#include<iostream>
#include<cmath>
#include<vector>
#include "include/Orthogonal.h"

double legendre(int ordre,int j, double x)
{
    switch (ordre)
    {
    case 0:
        return 1;
    case 1:
        return x-j*dx;
    case 2:
        return (x-j*dx)*(x-j*dx)-(1.0/12.0)*dx*dx;
    
    default:
        std::cout<<"higher ordre is not available, you want to compute the ordre: "<<ordre<<std::endl; 
        break;
    }
}

double deriv_legendre(int ordre,int j, double x)
{
    switch (ordre)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2*(x-j*dx)*(x-j*dx);
    
    default:
        std::cout<<"higher ordre is not available, you want to compute the ordre: "<<ordre<<std::endl; 
        break;
    }
}

double coeff(int ordre)
{
    switch (ordre)
    {
    case 0:
        return 1;
    case 1:
        return 12.0/dx;
    case 2:
        return 180.0/(dx*dx);
    
    default:
        std::cout<<"higher ordre is not available, you want to compute the ordre: "<<ordre<<std::endl; 
        break;
    }
}