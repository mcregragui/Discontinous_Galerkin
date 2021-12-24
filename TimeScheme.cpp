#include "include/SpaceScheme.h"
#include "include/TimeScheme.h"
#include <cassert>


std::vector<double> multiply(double scalar,std::vector<double> U )
{
    for(int i=0;i<U.size();i++)
    {
        U[i]=scalar*U[i];
    }
    return U;
}

std::vector<double> add(std::vector<double> U1,std::vector<double> U2)
{
    
    assert(U1.size()==U2.size());

    std::vector<double> V(U1.size(),0);
    for(int i=0;i<U1.size();i++)
    {
        V[i]=U1[i]+U2[i];
    }
     
    return V;
}



std::vector<double> Update(std::vector<double> U, int flux)
{
    std::vector<double> temp0;
    std::vector<double> temp1;
    std::vector<double> temp2;
    std::vector<double> temp3;
    std::vector<double> temp4;

    std::vector<double> U0;
    std::vector<double> U1;
    std::vector<double> U2;
    std::vector<double> U3;


    // temp1=LH(U,flux);
    // temp2=multiply(dt,temp1);
    // U=add(U,temp2);
    switch (r)
    {
    case 1:
        temp1=LH(U,flux);
        temp2=multiply(dt,temp1);
        U=add(U,temp2);

    case 2:
        U0=U;
        temp1=LH(U,flux);
        temp2=multiply(dt,temp1);
        U=add(U,temp2);
        U1=U;
        temp1=multiply(0.5,U0);
        temp2=multiply(0.5,U1);
        temp3=LH(U1,flux);
        temp4=multiply(dt*0.5,temp3);
        U=add(temp1,temp2);
        U=add(U,temp4);
        



        
    
        

    
    default:
        break;
    }
    return U;
}

