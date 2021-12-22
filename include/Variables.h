#include<iostream>

extern double dx, dt, adv, L;
extern int ord, r;
extern std::vector<double> sol(ord*std::floor(L/dx)); 