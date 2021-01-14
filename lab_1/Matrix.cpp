#define _CRT_SECURE_NO_WARNINGS
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

int Matrix::count = 0;

// ����������� �� ���������
Matrix::Matrix()
{
	count++;

	height = 1;
	width = 1;

	coef = new int[1];
	coef[0] = 0;
}

// ����������� � �����������
Matrix::Matrix(int new_width, int new_height)
{
	try
	{	
		if (new_width <= 0 || new_height <= 0) 
			throw std::runtime_error("Invalid matrix size");

		count++;

		height = new_height;
		width = new_width;

		coef = new int[height * width];

		for (int i = 0; i < width * height; i++)
			coef[i] = 0;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

// ����������� � �����������
Matrix::Matrix(int new_width, int new_height, int* coefs)
{	
	try
	{
		if (new_width <= 0 || new_height <= 0)
			throw std::runtime_error("Invalid matrix size");

		count++;

		height = new_height;
		width = new_width;

		coef = new int[height * width];

		for (int i = 0; i < width * height; i++)
		{
			if (!coefs[i])
				throw std::runtime_error("Invalid input coefficents");
			else
				coef[i] = coefs[i];
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

// ����������
Matrix::~Matrix()
{
	count--;
	//delete[] coef;
}


// int Matrix::get_count()
// ���������� ���������� ��������-������
// return - ���-�� ��������� ��������-������, int
int Matrix::get_count() 
{
	return count;
}

// int Matrix.get_w()
// ���������� ������ �������
// return - ������ �������, int
int Matrix::get_w()
{
	return width;
}

// int Matrix.get_h()
// ���������� ������ �������
// return - ������ �������, int
int Matrix::get_h()
{
	return height;
}

// void Matrix.input_coeffs()
// �������� ���� ������������� ������� ����� �������
void Matrix::input_coeffs()
{
	int number;

	for (int i = 0; i < width * height; i++)
	{
		std::cin >> number;
		coef[i] = number;
		getchar();
	}
}

// int Matrix.get_coef(int x, int y)
// ���������� ����������� ������� � �������� �������
// args:
// - int x - ����� �������, ����������� �������� ���� �������
// - int y - ����� ������, ����������� ������� ���� �������
// return - ����������� � ������� � �������� �������, int
int Matrix::get_coef(int x, int y)
{
	try {
		if (x < 0 || x > width - 1 || y < 0 || y > height - 1)
			throw std::runtime_error("Invalid coefficent coordinates");

		return coef[y * width + x];
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
}

// bool Matrix.change_coeff(int x, int y, int new_coef)
// �������� ����������� � ������� � �������� �������
// args:
// - int x - ����� �������, � ������� ����� ���������� ������
// - int y - ����� ������, � ������� ����� ���������� ������
// - int new_coef - ����� �������� ������������ � �������� �������
// return - false, ���� ������� ���������� ������� � ������� - true �����.
bool Matrix::change_coeff(int x, int y, int new_coef)
{
	try {
		if (x < 0 || x > width - 1 || y < 0 || y > height - 1)
			throw std::runtime_error("Invalid coefficent coordinates");

		coef[y * width + x] = new_coef;
		return true;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return false;
	}
}

// void Matrix.find_coeff()
// ����� ������������ �������
// args:
// - int coef_to_find - �����������, ������� �������� ���� �����
// - int *x - ��������� �� int, � ������� ������� �������� ����� ������� ���������� ������������ (-1 ���� �� ������)
// - int *y - ��������� �� int, � ������� ������� �������� ����� ������ ���������� ������������ (-1 ���� �� ������)
void Matrix::find_coeff(int coef_to_find, int* x, int* y)
{	
	int result_x = -1;
	int result_y = -1;

	for (int i = 0; i < width * height; i++)
		if (coef[i] == coef_to_find)
		{
			result_x = i % width;
			result_y = i / width;
		}

	*x = result_x;
	*y = result_y;
}

// void Matrix.sort_columns()
// ���������� �������� �������
void Matrix::sort_columns()
{
	for (int x = 0; x < width; x++)
	{
		for (int cur_step = 0; cur_step < height; cur_step++)
		{
			int min = INT_MAX;
			int min_id = -1;

			for (int y = cur_step; y < height; y++)
			{
				if (coef[y * width + x] < min)
				{
					min = coef[y * width + x];
					min_id = y;
				}
			}

			coef[min_id * width + x] = coef[cur_step * width + x];
			coef[cur_step * width + x] = min;
		}
	}
}

// void Matrix.sort_lines()
// ���������� ����� �������
void Matrix::sort_lines()
{
	for (int y = 0; y < height; y++)
	{
		for (int cur_step = 0; cur_step < width; cur_step++)
		{
			int min = INT_MAX;
			int min_id = -1;

			for (int x = cur_step; x < width; x++)
			{
				if (coef[y * width + x] < min)
				{
					min = coef[y * width + x];
					min_id = x;
				}
			}

			coef[y * width + min_id] = coef[y * width + cur_step];
			coef[y * width + cur_step] = min;
		}
	}
}

// void Matrix.print() 
// ����� ������� � �������
/*
void Matrix::print()
{
	std::cout << "Matrix " << width << "x" << height << ":" << std::endl;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
			std::cout << coef[y * width + x] << ' ';

		std::cout << std::endl;
	}
}
*/

// string Matrix.to_string()
// ��������� �������������� �������
// return - ��� � ��������
char* Matrix::to_string()
{
	int size = 12 + log(width) + log(height);
	
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			if (coef[y * width + x] > 0)
				size += log(coef[y * width + x]) + 1;
			else if (coef[y * width + x] < 0)
				size += log(-coef[y * width + x]) + 1;
			else
				size += 2;

	char* buffer = new char[32];
	char* result = new char[size];

	sprintf(result, "%s", "Matrix: ");

	sprintf(buffer, "%i", width);
	strcat(result, buffer);

	strcat(result, "x");

	sprintf(buffer, "%i", height);
	strcat(result, buffer);

	strcat(result, "\n");

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			sprintf(buffer, "%i", coef[y * width + x]);
			strcat(result, buffer);
			strcat(result, " ");
		}

		strcat(result, "\n");
	}
	
	return result;
}

// Matrix* Matrix::operator+(Matrix b)
// ���������� ��������� �������� ������
Matrix* Matrix::operator+(Matrix b)
{
	Matrix* c = new Matrix(width, height);

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			c->change_coeff(x, y, get_coef(x, y) + b.get_coef(x, y));
		}
	}

	return c;
}

// Matrix* Matrix::operator-(Matrix b)
// ���������� ��������� ��������� ������
Matrix* Matrix::operator-(Matrix b)
{
	Matrix* c = new Matrix(width, height);

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			c->change_coeff(x, y, get_coef(x, y) - b.get_coef(x, y));
		}
	}

	return c;
}

// Matrix* Matrix::operator[](unsigned i)
// ���������� ��������� �������������� �������
Matrix* Matrix::operator[](unsigned i)
{
	size_t wt = height == 1 ? 1 : width;
	Matrix* d = new Matrix(wt, 1);

	for (int ik = 0; ik < wt; ik++)
	{
		d->change_coeff(ik, 0, this->get_coef(ik, i));
	}

	return d;
}

// void Matrix::operator()(int x, int y, int new_coef)
// ���������� ��������� ������ ������� ��� �������
void Matrix::operator()(int x, int y, int new_coef)
{
	change_coeff(x, y, new_coef);
}

// Matrix& Matrix::operator=(Matrix& m2)
// ���������� ��������� ������������ ������
Matrix& Matrix::operator=(Matrix& m2)
{
	delete[] coef;

	height = m2.get_h();
	width = m2.get_w();

	coef = new int[height * width];

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			coef[x + y * height] = m2.get_coef(x, y);

	return *this;
}

// ostream& operator<<(ostream& os, Matrix& p) 
// ���������� ��������� ������ � �����
std::ostream& operator<<(std::ostream& os, Matrix& p) 
{
	os << "Matrix " << p.get_w() << "x" << p.get_h() << ":" << std::endl;

	for (int y = 0; y < p.get_h(); y++)
	{
		for (int x = 0; x < p.get_w(); x++)
			os << p.get_coef(x, y) << ' ';

		os << std::endl;
	}

	return os;
}

// istream& operator>>(istream& is, Matrix& p)
// ���������� ��������� ������ �� ������
std::istream& operator>>(std::istream& is, Matrix& p)
{
	is >> p.width >> p.height;

	delete[] p.coef;
	p.coef = new int[p.height * p.width];

	for (int i = 0; i < p.height * p.width; i++)
		is >> p.coef[i];
	
	return is;
}

// std::ofstream& operator<<(std::ofstream& os, Matrix& p) 
// ���������� ��������� ������ � �������� �����
std::ofstream& operator<<(std::ofstream& os, Matrix& p) 
{
	os << p.get_w() << ' ' << p.get_h() << ' ';

	for (int y = 0; y < p.get_h(); y++)
		for (int x = 0; x < p.get_w(); x++)
			os << p.get_coef(x, y) << ' ';

	return os;
}

// std::ifstream& operator>>(std::ifstream& is, Matrix& p)
// ���������� ��������� ������ �� ��������� ������
std::ifstream& operator>>(std::ifstream& is, Matrix& p)
{
	is >> p.width >> p.height;

	if (is.peek() == EOF)
		return is;

	delete[] p.coef;
	p.coef = new int[p.height * p.width];

	for (int i = 0; i < p.height * p.width; i++)
		is >> p.coef[i];
	
	return is;
}