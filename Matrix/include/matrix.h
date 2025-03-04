#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <cstdlib> // #include 	<stdlib.h>
#include <conio.h>
#include <time.h>
#include <sstream>
#include <cmath>

using namespace std;
enum MatrixType
{
    Identity, // 0
    Random // 1
};

class Matrix{
private:
	int rows;
	int cols;
	float **data;
public:
	Matrix( int rows_, int cols_);                   // two arguments only
	Matrix(int rows_, int cols_, float val);
	Matrix(int rows_, int cols_, MatrixType m_type);
	/*Copy constructor: to prevent shallow copy*/
	Matrix(const Matrix& m);
	~Matrix();
	int get_rows() const;
	int get_cols() const;
	void print() const;
	float& access(int r_ind, int c_ind);
    float& operator()(int r_ind, int c_ind);
	Matrix operator+(const Matrix& m) const;
	Matrix operator-(const Matrix& m) const;
	Matrix operator*(float val) const;
	Matrix operator/(float val) const;
	Matrix operator*(const Matrix& m) const;
	/*Bonus: Matrix Inverse*/
	Matrix operator/(const Matrix& m) const;
	bool operator==(const Matrix& m) const;
	bool operator!=(const Matrix& m) const;
	bool isIdentity() const;
	bool isIdempotent() const;
	bool isSquare() const;
	bool isSymmetric() const;
	bool isUpperTriangle() const;
	bool isLowerTriangle() const;
	Matrix transpose() const;
	void fill(float val);
	float minElement() const;
	float maxElement() const;
	/*Bonus: Determinant*/
	float determinant() const;
	/*Bonus: stringify Matrix*/
	string toString() const;
};

#endif // MATRIX_H
