#include "include/Variables.h"
#include "include/TimeScheme.h"
#include "include/Quadrature.h"
#include "include/Orthogonal.h"
#include "include/limiter.h"
#include "include/Flux.h"
#include "include/InitCondition.h"
#include<fstream>

double dx(0.1), dt(0.01), adv(1), L(40);
int ord(1), r(2);


int main()
{
    std::vector<double> sol(ord*std::floor(L/dx),0);
     
    for(int i=0;i<ord*std::floor(L/dx);i++)
    {
        sol[i]=u0(i*dx);
    }


    int n=10;
    std::vector<double> temp(ord*std::floor(L/dx),0);
    for(int i=0;i<ord*std::floor(L/dx);i++)
    {
        temp[i]=u0(i*dx-adv*n*dt);
    }
    
    for(int i=0;i<n;i++)
    {
        sol=Update(sol,3);
    }

    std::ofstream myfile;
    myfile.open ("example.txt");
    for(int i=0;i<std::floor(L/dx);i++)
    {
        myfile <<i*dx<<" "<<temp[ord*i]<<" "<<sol[ord*i]<<std::endl;
    }
   
    myfile.close();

}

