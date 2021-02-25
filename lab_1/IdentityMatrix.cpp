#define _CRT_SECURE_NO_WARNINGS
#include "IdentityMatrix.h"
#include <sstream>

// IdentityMatrix::IdentityMatrix() : Matrix() 
// Вызов конструктора класса-родителя с изменением значения коэффициента
IdentityMatrix::IdentityMatrix() : Matrix()
{
	this->change_coeff(0, 0, 1);
}

// IdentityMatrix::IdentityMatrix(int new_width, int new_height) : Matrix(new_width, new_height) 
// Вызов конструктора класса-родителя с изменением значения коэффициента
IdentityMatrix::IdentityMatrix(int new_width, int new_height) : Matrix(new_width, new_height)
{
	for (int i = 0; i < this->get_w() * this->get_h(); i++)
		this->change_coeff(i % this->get_h(), i / this->get_h(), i % this->get_h() == i / this->get_h() ? 1 : 0);
}

// IdentityMatrix::IdentityMatrix(int new_width, int new_height, int* coefs) : IdentityMatrix(new_width, new_height) {}
// Перегрузка конструктора класса-родителя - вызов собственного конструктора без последнего аргумента
IdentityMatrix::IdentityMatrix(int new_width, int new_height, int* coefs) : IdentityMatrix(new_width, new_height) {}

// void IdentityMatrix::input_coeffs() {}
// Перегрузка метода input_coeffs класса-родителя - единичные матрицы не изменяются
void IdentityMatrix::input_coeffs() {}

// bool IdentityMatrix::change_coeff(int x, int y, int new_coef) 
// Перегрузка метода change_coeff класса-родителя - на главной диагонале могут быть только единицы, в остальных местах - нули
// return - false
bool IdentityMatrix::change_coeff(int x, int y, int new_coef)
{
	return Matrix::change_coeff(x, y, x == y ? 1 : 0);
}

// void IdentityMatrix::sort_columns() {}
// Перегрузка метода sort_columns класса-родителя - единичные матрицы не нуждаются в сортировке
void IdentityMatrix::sort_columns() {}

// void IdentityMatrix::sort_lines() {}
// Перегрузка метода sort_lines класса-родителя - единичные матрицы не нуждаются в сортировке
void IdentityMatrix::sort_lines() {}

// string TriMatrix.to_string()
// Строковое представвление единичной матрицы
// return - как в описании
char* IdentityMatrix::to_string()
{
	int size = 21 + log(this->get_w()) + log(this->get_h());

	char* buffer = new char[32];
	char* result = new char[size];

	sprintf(result, "Identity Matrix: %ix%i\n", this->get_w(), this->get_h());
	return result;
}
