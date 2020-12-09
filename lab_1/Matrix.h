#pragma once
#include <iostream>

class Matrix {
	static int count;

public:
	static int get_count();
	static void clear_file();
	static void clear_bin_file();
	static std::ofstream open_file_save();
	static std::ifstream open_file_load();
	static std::ofstream open_file_save_bin();
	static std::ifstream open_file_load_bin();

	Matrix();
	Matrix(int new_width, int new_height);
	Matrix(int new_width, int new_height, int* coefs);

	~Matrix();

	int get_w();
	int get_h();
	int get_coef(int x, int y);

	void input_coeffs();
	bool change_coeff(int x, int y, int new_coef);
	void find_coeff(int coef_to_find, int* x, int* y);

	void sort_lines();
	void sort_columns();

	void print(); // TODO: Remove


	Matrix* operator+(Matrix b);
	Matrix* operator-(Matrix b);
	Matrix* operator[](unsigned i);
	void operator()(int x, int y, int new_coef);
	Matrix& operator=(Matrix& m2);

	friend std::ostream& operator<<(std::ostream& os, Matrix& p);
	friend std::istream& operator>>(std::istream& is, Matrix& p);

	friend std::ofstream& operator<<(std::ofstream& os, Matrix& p);
	friend std::ifstream& operator>>(std::ifstream& is, Matrix& p);


private:
	int height;
	int width;
	int* coef;
};
