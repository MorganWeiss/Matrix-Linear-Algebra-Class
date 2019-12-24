#pragma once
#include <vector>
#include <algorithm>

template<class T>
class Matrix
{
public:
	Matrix() = default;
	Matrix(Matrix& source);
	Matrix(int _rows, int _cols, const T& fill);
	Matrix(int _rows, int _cols);
	Matrix(Matrix&& move) noexcept;
	Matrix& operator=(Matrix&& move) noexcept;			
	~Matrix() noexcept {};


	// Get row and column sizes
	int get_rows() { return this->rows; }
	int get_cols() { return this->cols; }
	void print() const;

	// Member element access
	T& operator()(const int& row, const int& col);
	const T& operator()(const int& row, const int& col) const;

	// Define swap function
	void swap(Matrix<T>& other) 
	{
		using std::swap;
		swap(mat, other.mat);
		swap(rows, other.rows);
		swap(cols, other.cols);
	}


private:
	int rows, cols;
	std::vector<std::vector<T>> mat;

};


template<class T>
Matrix<T>::Matrix(Matrix<T>& source)
{
	mat = source.mat;
	rows = source.get_rows();
	cols = source.get_cols();
}

template<class T>
Matrix<T>::Matrix(int _rows, int _cols, const T& fill)
{
	mat.resize(_rows);
	for (unsigned i = 0; i < mat.size(); ++i)
		mat[i].resize(_cols, fill);

	rows = _rows;
	cols = _cols;
}

template<class T>
Matrix<T>::Matrix(int _rows, int _cols)
{
	mat.resize(_rows);
	for (unsigned i = 0; i < mat.size(); ++i)
		mat[i].resize(_cols);

	rows = _rows;
	cols = _cols;
}

template<class T>
Matrix<T>::Matrix(Matrix&& move) noexcept
{
	move.swap(*this);
}

template <class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& move) noexcept {
	move.swap(*this);
	return *this;
}

template<class T>
void Matrix<T>::print() const
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

// Access the individual elements                                                                                                                                             
template<typename T>
T& Matrix<T>::operator()(const int& row, const int& col) {
	return this->mat[row][col];
}

// Access the individual elements (const)                                                                                                                                     
template<typename T>
const T& Matrix<T>::operator()(const int& row, const int& col) const {
	return this->mat[row][col];
}