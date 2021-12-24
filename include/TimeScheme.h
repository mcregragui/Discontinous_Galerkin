#include<iostream>
#include<cmath>
#include<vector>
#include "Variables.h"
#include "Flux.h"
#include "limiter.h"
#include "SpaceScheme.h"

std::vector<double> multiply(double scalar,std::vector<double> U );

std::vector<double> add(std::vector<double> U1,std::vector<double> U2);

std::vector<double> Update(std::vector<double> U, int flux);

