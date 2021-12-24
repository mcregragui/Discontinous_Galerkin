#include<iostream>
#include<cmath>
#include<vector>
#include "Variables.h"
#include "Orthogonal.h"
#include "TimeScheme.h"
#include "InitCondition.h"
#include "template.h"

std::vector<double> FU(std::vector<double>& U);

std::vector<double> Quadrature(std::vector<double>& sol);

std::vector<double> Quadrature0();