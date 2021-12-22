#include<iostream>
#include<cmath>
#include<vector>
#include "include/limiter.h"


double minmod(double a, double b, double c)
{
    if(a*b>0 && a*c>0)
    {
        double m=fabs(a);
        if(m>fabs(b))
        {
            m=fabs(b);
        }
        if(m>fabs(c))
        {
            m=fabs(c);
        }
        return sign(a)*m;
    }
    else
    {
        return 0;
    }
}

double minmod_shu(double a, double b, double c, double M)
{
    M=(2/3)*M;
    if( fabs(a)<M)
    {
        return a;
    }
    else
    {
        return minmod(a,b,c);
    }
}

int sign(double a)
{
    if(a>=0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

double left(int j)
{
    switch (ord)
    {
    case 1:
        return 0;
    
    case 2:
        return 6*sol[ord*j+1];

    case 3:
        return 6*sol[ord*j+1]+30*sol[ord*j+2];
    
    default:
        std::cout<<"higher order: "<<ord<<std::endl;
        break;
    }
}

double wright(int j)
{
    switch (ord)
    {
    case 1:
        return 0;
    
    case 2:
        return 6*sol[ord*j+1];

    case 3:
        return 6*sol[ord*j+1]-30*sol[ord*j+2];
    
    default:
        std::cout<<"higher order: "<<ord<<std::endl;
        break;
    }
}
