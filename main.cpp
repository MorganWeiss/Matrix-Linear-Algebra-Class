#include <iostream>
#include "Matrix.h"
#include "LinAlg.h"

using namespace np;

int main()
{

	Matrix<int> mat1(4, 4, 1);
	mat1.print();

	auto mat2 = mat1;
	mat2.print();

	for (int i = 0; i < mat1.get_rows(); ++i)
	{
		for (int j = 0; j < mat2.get_cols(); ++j)
		{
			mat1(i, j) = i + 1;
		}
	}

	mat1.print();
	mat1 = np::transpose(mat1);
	mat1.print();

	Matrix<int> mat3(2, 2, 1);
	mat3 = np::multiply(mat3, 2);
	mat3.print();

	Matrix<int> mat4(2, 2, 1);
	Matrix<int> mat5 = np::multiply(mat3, mat4);
	mat5.print();

	mat5 = np::add(mat5, mat3);
	mat5.print();

	mat5 = np::subtract(mat5, mat3);
	mat5.print();

	Matrix<double> mat6(2, 2, 2);
	mat6 = np::normalize(mat6);
	mat6.print();

	auto vec = np::flatten(mat6);
	vec.print();


	std::cin.get();
}