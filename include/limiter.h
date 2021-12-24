#include<iostream>
#include<cmath>
#include<vector>
#include "Variables.h"

double minmod(double a, double b, double c);

double minmod_shu(double a, double b, double c, double M);

int sign(double a);

double left(std::vector<double>& sol,int j);

double wright(std::vector<double>& sol,int j);

double leftMod(std::vector<double>& sol,int j);

double wrightMod(std::vector<double>& sol,int j);