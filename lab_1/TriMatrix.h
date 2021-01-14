#pragma once
#include "Matrix.h"

class TriMatrix : public Matrix {
public:
	TriMatrix();
	TriMatrix(int new_width, int new_height);
	TriMatrix(int new_width, int new_height, int* coefs, bool is_upper_tri);

	bool change_coeff(int x, int y, int new_coef);

	void sort_lines();
	void sort_columns();

	virtual char* to_string();

private:
	bool is_upper_tri;
};
