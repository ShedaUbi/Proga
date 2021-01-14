#define _CRT_SECURE_NO_WARNINGS
#include "TriMatrix.h"
#include <sstream>

// TriMatrix.TriMatrix() : Matrix() 
// Вызов конструктора класса-родителя и установка значения is_upper_tri по умолчанию - true
TriMatrix::TriMatrix() : Matrix() 
{
	is_upper_tri = true;
}

// TriMatrix.TriMatrix(int new_width, int new_height) : Matrix(new_width, new_height) 
// Вызов конструктора класса-родителя и установка значения is_upper_tri по умолчанию - true
TriMatrix::TriMatrix(int new_width, int new_height) : Matrix(new_width, new_height) 
{
	is_upper_tri = true;
}

// TriMatrix.TriMatrix(int new_width, int new_height, int* coefs, bool is_upper) : Matrix(new_width, new_height, coefs) 
// Вызов конструктора класса-родителя, установка значения is_upper_tri, обнуление лишних коэффициентов матрицы
TriMatrix::TriMatrix(int new_width, int new_height, int* coefs, bool is_upper) : Matrix(new_width, new_height, coefs) 
{
	is_upper_tri = is_upper;

	for (int y = 0; y < this->get_h(); y++)
		for (int x = 0; x < this->get_w(); x++)
			if (is_upper_tri && x < y || !is_upper_tri && x > y)
				this->change_coeff(x, y, 0);
}

// bool TriMatrix.change_coeff(int x, int y, int new_coef)
// Перегрузка метода change_coeff класса-родителя - пресекаются попытки изменить не используемый в треугольной матрице коэффициент
// return - false, если изменяется не-треугольный элемент, иначе - true, если установка значения успешна.
bool TriMatrix::change_coeff(int x, int y, int new_coef)
{
	if (x < 0 || x > this->get_w() - 1 || y < 0 || y > this->get_h() - 1)
		return false;

	if (new_coef != 0 && (is_upper_tri && x < y || !is_upper_tri && x > y))
		return false;

	return Matrix::change_coeff(x, y, new_coef);
}

// void TriMatrix.sort_columns()
// Перегрузка метода sort_columns класса-родителя - сортируются только используемые коэффициенты
void TriMatrix::sort_columns()
{
	for (int x = is_upper_tri ? 1 : 0; x < this->get_w() - (is_upper_tri ? 0 : 1); x++)
	{
		for (int cur_step = is_upper_tri ? 0 : x; cur_step < (is_upper_tri ? x : this->get_h()); cur_step++)
		{
			int min = INT_MAX;
			int min_id = -1;

			for (int y = cur_step; y < (is_upper_tri ? x : this->get_h()); y++)
			{
				if(this->get_coef(x, y) < min)
				{
					min = this->get_coef(x, y);
					min_id = y;
				}
			}

			this->change_coeff(x, min_id, this->get_coef(x, cur_step));
			this->change_coeff(x, cur_step, min);
		}
	}
}

// void TriMatrix.sort_lines()
// Перегрузка метода sort_lines класса-родителя - сортируются только используемые коэффициенты
void TriMatrix::sort_lines()
{
	for (int y = is_upper_tri ? 0 : 1; y < this->get_h() - (is_upper_tri ? 1 : 0); y++)
	{
		for (int cur_step = is_upper_tri ? y : 0; cur_step < (is_upper_tri ? this->get_w() : y); cur_step++)
		{
			int min = INT_MAX;
			int min_id = -1;

			for (int x = cur_step; x < (is_upper_tri ? this->get_w() : (y + 1)); x++)
			{
				if (this->get_coef(x, y) < min)
				{
					min = this->get_coef(x, y);
					min_id = x;
				}
			}

			this->change_coeff(min_id, y, this->get_coef(cur_step, y));
			this->change_coeff(cur_step, y, min);
		}
	}
}

// string TriMatrix.to_string()
// Строковое представвление треугольной матрицы
// return - как в описании
char* TriMatrix::to_string()
{
	int size = 21 + log(this->get_w()) + log(this->get_h());

	for (int y = 0; y < this->get_h(); y++)
		for (int x = 0; x < this->get_w(); x++)
			if (this->get_coef(x, y) > 0)
				size += log(this->get_coef(x, y)) + 1;
			else if (this->get_coef(x, y) < 0)
				size += log(-(this->get_coef(x, y))) + 1;
			else
				size += 2;

	char* buffer = new char[32];
	char* result = new char[size];

	sprintf(result, "%s", "Triangle Matrix: ");

	sprintf(buffer, "%i", this->get_w());
	strcat(result, buffer);

	strcat(result, "x");

	sprintf(buffer, "%i", this->get_h());
	strcat(result, buffer);

	strcat(result, "\n");

	for (int y = 0; y < this->get_h(); y++)
	{
		for (int x = 0; x < this->get_w(); x++)
		{
			sprintf(buffer, "%i", this->get_coef(x, y));
			strcat(result, buffer);
			strcat(result, " ");
		}

		strcat(result, "\n");
	}

	return result;
}