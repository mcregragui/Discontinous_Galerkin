#pragma once
#include <vector>
#include <iostream>
#include <omp.h>
/* A TEMPLATE FOR VECTORS OPERATORS OVERLOADING  */


template <typename T>
std::vector<T>  operator +(std::vector<T> const& v1, std::vector<T> const& v2)
{
	int size = (int)v1.size();
	std::vector<T> res(size, 0);

	for (int i = 0; i < size; i++)
		res[i] = v1[i] + v2[i];

	return res;
};


template <typename T>
std::vector<T>  operator -(std::vector<T> const& v1, std::vector<T> const& v2)
{
	int size = (int)v1.size();
	std::vector<T> res(size, 0);

	for (int i = 0; i < size; i++)
		res[i] = v1[i] - v2[i];

	return res;
};



//warning possible loss of data, example: double * std::vector<int> = std::vector<int>
template <typename T, typename S>
std::vector<T>  operator *(S const a, std::vector<T> const &v)
{
	int size = (int)v.size();
	std::vector<T> res(size, 0);

	for (int i = 0; i < size; i++)
		res[i] = a*v[i];

	return res;
};


template<typename T>
std::vector<T> operator *(std::vector<std::vector<T>>& A, std::vector<T>& b)
{
	int size = (int)b.size();
	std::vector<T> result(size, 0.0);
	#pragma omp parallel 
	{
		#pragma omp for collapse(2) schedule(dynamic)
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				#pragma omp atomic
				result[i] += A[i][j] * b[j];
	}
	return result;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
	os << "   ";
	for (T x : v)
		os << x << "    ";
	os << '\n';
	return os;
};
