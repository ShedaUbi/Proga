#pragma once

class Matrix {
	static int count;

public:
	static int get_count();

	Matrix(); 
	Matrix(int new_width, int new_height); 
	Matrix(int new_width, int new_height, int* coefs); 

	~Matrix();
	
	int get_w();
	int get_h();
	int get_coef(int x, int y);
	
	void input_coeffs();
	bool change_coeff(int x, int y, int new_coef);
	void find_coeff(int coef_to_find, int *x, int *y);

	void sort_lines();
	void sort_columns();

	char* to_string();
	void print();

private:
	int height;
	int width;
	int* coef;
};