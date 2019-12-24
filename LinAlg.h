#pragma once
#include <assert.h>
#include "Matrix.h"



namespace np
{

	// Get the transpose of matrix 
	template <class T>
	Matrix<T> transpose(Matrix<T>& mat)
	{
		Matrix<T> result(mat.get_cols(), mat.get_rows(), mat(0,0));
		for (int i = 0; i < mat.get_rows(); ++i)
		{
			for (int j = 0; j < mat.get_cols(); ++j)
			{
				result(i, j) = mat(j, i);
			}
		}
		return result;
	}

	// Scalar multiplication 
	template <class T>
	Matrix<T> multiply(Matrix<T>& mat, const T value)
	{
		Matrix<T> result(mat.get_cols(), mat.get_rows());
		for (int i = 0; i < mat.get_rows(); ++i)
		{
			for (int j = 0; j < mat.get_cols(); ++j)
			{
				result(i, j) = mat(i, j) * value;
			}
		}
		return result;
	}

	// Multiply two matrices
	template <class T>
	Matrix<T> multiply(Matrix<T>& mat1, Matrix<T>& mat2)
	{
		assert(mat1.get_cols() == mat2.get_rows());
		Matrix<T> result(mat1.get_rows(), mat2.get_cols());
		for (int i = 0; i < mat1.get_rows(); ++i)
		{
			for (int j = 0; j < mat2.get_cols(); ++j)
			{
				for (int k = 0; k < result.get_rows(); ++k)
				{
					result(i, j) += mat1(i, k) * mat2(k, j);
				}
			}
		}
		return result;
	}

	// Add two matrices
	template <class T>
	Matrix<T> add(Matrix<T>& mat1, Matrix<T>& mat2)
	{
		assert(mat1.get_rows() == mat2.get_rows() && mat1.get_cols() == mat2.get_cols());
		Matrix<T> result(mat1.get_rows(), mat2.get_cols());
		for (int i = 0; i < mat1.get_rows(); ++i)
		{
			for (int j = 0; j < mat2.get_cols(); ++j)
			{
				result(i, j) += mat1(i, j) + mat2(i, j);
			}
		}
		return result;
	}

	// Subtract two matrices  
	template <class T>
	Matrix<T> subtract(Matrix<T>& mat1, Matrix<T>& mat2)
	{
		assert(mat1.get_rows() == mat2.get_rows() && mat1.get_cols() == mat2.get_cols());
		Matrix<T> result(mat1.get_rows(), mat2.get_cols());
		for (int i = 0; i < mat1.get_rows(); ++i)
		{
			for (int j = 0; j < mat2.get_cols(); ++j)
			{
				result(i, j) += mat1(i, j) - mat2(i, j);
			}
		}
		return result;
	}

	// Normalize the entries of the matrix to be from 0 to 1
	template <class T>
	Matrix<T> normalize(Matrix<T>& mat)
	{
		Matrix<T> result(mat.get_rows(), mat.get_cols());
		for (int i = 0; i < mat.get_rows(); ++i)
		{
			double sum = 0.0;
			for (int j = 0; j < mat.get_cols(); ++j)
			{
				sum += mat(i, j);
			}

			for (int j = 0; j < mat.get_cols(); ++j)
			{
				result(i, j) = mat(i, j) / sum;
			}
		}
		return result;
	}

	// Convert 2D matrix to 1D
	template<class T>
	Matrix<T> flatten(Matrix<T>& mat)
	{
		Matrix<T> v(1, mat.get_rows() * mat.get_cols());

		for (int i = 0; i < mat.get_rows(); ++i) 
		{
			for (int j = 0; j < mat.get_cols(); ++j) 
			{
				v(0, i * mat.get_cols() + j) = mat(i, j);
			}
		}
		return v;
	}



}


