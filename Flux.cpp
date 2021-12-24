#include<iostream>
#include<cmath>
#include<vector>
#include <algorithm>
#include "include/Flux.h"


double EO(double a, double b)
{
    if(adv>0)
    {
        return a*adv;
    }
    else
    {
        return b*adv;
    }
}

double G(double a, double b)
{
    if (adv>0)
    {
        return a*adv;
    }
    else
    {
        return b*adv;
    }
}

double LF(double a, double b)
{
    return a*adv;
}

double LLF(double a, double b)
{
    return a*adv;
}

double Roe(double a, double b)
{
    if (adv>0)
    {
        return a*adv;
    }
    else
    {
        return b*adv;
    }   
}

double Flux(int flux,double a, double b)
{
    switch (flux)
    {
    case 1:
        return EO(a,b);

    case 2:
        return G(a,b);
    
    case 3:
        return LF(a,b);
    
    case 4:
        return Roe(a,b);
    
    default:
        std::cout<<"There is no such an implemented flux"<<std::endl;
        break;
    }
}