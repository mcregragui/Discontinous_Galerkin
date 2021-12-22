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

double Flux(char flux,double a, double b)
{
    switch (flux)
    {
    case 'EO':
        return EO(a,b);

    case 'G':
        return G(a,b);
    
    case 'LF':
        return LF(a,b);
    
    case 'Roe':
        return Roe(a,b);
    
    default:
        std::cout<<"There is no such an implemented flux"<<std::endl;
        break;
    }
}