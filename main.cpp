#include "include/Variables.h"
#include "include/TimeScheme.h"
#include "include/Quadrature.h"
#include "include/Orthogonal.h"
#include "include/limiter.h"
#include "include/Flux.h"
#include "include/InitCondition.h"
#include<fstream>

double dx(0.1), dt(0.001), adv(1), L(10);
int ord(3), r(2);


int main()
{
    std::vector<double> sol(ord*std::floor(L/dx),0);
    //std::vector<double> sol(ord*std::floor(L/dx),0);
     
    /*for(int i=0;i<ord*std::floor(L/dx);i++)
    {
        sol[i]=u0(i*dx);
    }*/
    sol=Quadrature0();


    int n=50;
    std::vector<double> temp(std::floor(L/dx),0);
    for(int i=0;i<std::floor(L/dx);i++)
    {
        temp[i]=u0(i*dx-adv*n*dt);
    }
    
    for(int i=0;i<n;i++)
    {
        sol=Update(sol,3);
    }

    std::ofstream myfile;
    myfile.open ("example.txt");
    std::vector<double> sol0(ord*std::floor(L/dx),0);
    sol0=Quadrature0();
    for(int i=0;i<std::floor(L/dx);i++)
    {
        myfile <<i*dx<<" "<<temp[i]<<" "<<transformp(sol,i*dx)[i]<<" "<<transformp(sol,i*dx)[i]-temp[i] <<std::endl;
    }
   
    myfile.close();

}

