#pragma once
#include<vector>
#include<iostream>

class Matrix {
public:

	Matrix(int X_dim, int Y_dim);

	float get(int X, int Y);

	void set(int X, int Y, float value);

	float determinant();

	Matrix SubMatrix(int column, int row);

	void print();

	Matrix operator* (Matrix input);
	Matrix operator* (float input);
	Matrix operator/ (float input);
	void operator= (Matrix input);

	Matrix inverse();

	Matrix cofactorMatrix();

	Matrix transpose();

	void clear();

	void resize(int X_dim, int Y_dim);

	unsigned int get_x_dim();
	unsigned int get_y_dim();

	std::vector<float> column_to_vector(int column);

private:
	std::vector<float> matrix;
	unsigned int x_dim, y_dim;
};