#pragma once
#include "Matrix.h"

class IdentityMatrix: public Matrix {
public:
	IdentityMatrix();
	IdentityMatrix(int new_width, int new_height);
	IdentityMatrix(int new_width, int new_height, int* coefs);

	void input_coeffs();
	bool change_coeff(int x, int y, int new_coef);

	void sort_lines();
	void sort_columns();
};
