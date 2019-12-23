#include "Matrix.h"


Matrix::Matrix(int X_dim, int Y_dim) {
	resize(X_dim, Y_dim);
}

float Matrix::get(int X, int Y) {
	if (X < 1 || Y < 1 || X > x_dim || Y > y_dim) {
		throw("Error: Index Out of Range");
	}
	return matrix[(X - 1) + ((Y - 1) * x_dim)];
}

void Matrix::set(int X, int Y, float value) {
	if (X < 1 || Y < 1 || X > x_dim || Y > y_dim) {
		throw("Error: Index Out of Range");
	}

	matrix[(X - 1) + ((Y - 1) * x_dim)] = value;
}

float Matrix::determinant() {
	if (x_dim != y_dim) {
		throw "Error: Can't calculate determinant of non-square matrix";
	}
	else if (x_dim == 1 && y_dim == 1) {
		return get(1, 1);
	}
	else if (x_dim == 2 && y_dim == 2) {
		return (get(1, 1) * get(2, 2)) - (get(2, 1) * get(1, 2));
	}
	else if (x_dim > 2 && y_dim > 2) {
		float sum = 0;
		for (int i = 1; i <= x_dim; i++) {
			sum += pow(-1, i - 1) * get(i, 1) * (SubMatrix(i, 1).determinant());
		}
		return sum;
	}
}

Matrix Matrix::SubMatrix(int column, int row) {
	Matrix SubMatrix(x_dim - 1, y_dim - 1);
	int length = (x_dim) * (y_dim);

	int i = 1;
	int j = 1;
	int x_add = 0;
	int y_add = 0;

	while (j < y_dim) {
		if (i == column) {
			x_add = 1;
		}
		if (j == row) {
			y_add = 1;
		}

		SubMatrix.set(i, j, get(i + x_add, j + y_add));

		i++;

		if (i == x_dim) {
			x_add = 0;
			i = 1;
			j++;
		}

	}

	return SubMatrix;
}

void Matrix::print() {
	std::cout << std::endl;
	for (int j = 0; j < y_dim; j++) {
		for (int i = 0; i < x_dim; i++) {
			std::cout << matrix[i + x_dim * j] << " ";
		}
		std::cout << std::endl;
	}
}

unsigned int Matrix::get_x_dim() {
	return x_dim;
}

unsigned int Matrix::get_y_dim() {
	return y_dim;
}

Matrix Matrix::operator* (Matrix input) {
	if (get_x_dim() != input.get_y_dim()) {
		throw("Cannot multiply matricies that do not have correct dimensions");
	}

	Matrix output(input.get_x_dim(), get_y_dim());

	float result;

	for (int i = 1; i <= output.get_x_dim(); i++) {
		for (int j = 1; j <= output.get_y_dim(); j++) {
			result = 0;
			for (int k = 1; k <= get_x_dim(); k++) {
				result += get(k, j) * input.get(i, k);
			}
			output.set(i, j, result);
		}
	}

	return output;
}

Matrix Matrix::operator* (float input) {
	Matrix output(x_dim, y_dim);
	for (int i = 1; i <= x_dim; i++) {
		for (int j = 1; j <= y_dim; j++) {
			output.set(i, j, get(i, j) * input);
		}
	}
	return output;
}

Matrix Matrix::operator/ (float input) {
	Matrix output(x_dim, y_dim);
	for (int i = 1; i <= x_dim; i++) {
		for (int j = 1; j <= y_dim; j++) {
			output.set(i, j, (get(i, j) / input));
		}
	}
	return output;
}

void Matrix::operator= (Matrix input) {
	for (int i = 1; i <= x_dim; i++) {
		for (int j = 1; j <= y_dim; j++) {
			set(i, j, (input.get(i, j)));
		}
	}
}

Matrix Matrix::inverse() {
	Matrix output(x_dim, y_dim);
	if (x_dim == 1 && y_dim == 1) {
		output.set(1, 1, 1 / get(1, 1));
		return output;
	}
	output = ((cofactorMatrix().transpose()) / determinant());
	return output;
}


Matrix Matrix::cofactorMatrix() {
	Matrix output(x_dim, y_dim);
	for (int i = 1; i <= x_dim; i++) {
		for (int j = 1; j <= y_dim; j++) {
			output.set(i, j, pow(-1,i+j)*(SubMatrix(i, j).determinant()));
		}
	}
	return output;
}

Matrix Matrix::transpose() {
	Matrix output(y_dim, x_dim);
	for (int i = 1; i <= x_dim; i++) {
		for (int j = 1; j <= y_dim; j++) {
			output.set(j, i, get(i, j));
		}
	}
	return output;
}

void Matrix::clear() {
	for (int i = 1; i <= x_dim; i++) {
		for (int j = 1; j <= y_dim; j++) {
			set(i, j, 0);
		}
	}
}

void Matrix::resize(int X_dim, int Y_dim){
	x_dim = X_dim;
	y_dim = Y_dim;
	matrix.resize(x_dim * y_dim);
	clear();
}

std::vector<float> Matrix::column_to_vector(int column) {
	std::vector<float> output;
	for (int i = 1; i <= y_dim; i++) {
		output.push_back(get(column, i));
	}
	return output;
}