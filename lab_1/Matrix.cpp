#define _CRT_SECURE_NO_WARNINGS
#include "Matrix.h"
#include <iostream>
#include <cstring>
//#include <stdlib.h> //for itoa

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
	count++; 

	height = new_height;
	width = new_width;

	coef = new int[height * width];

	for(int i = 0; i < width * height; i++)
		coef[i] = 0;
}

// ����������� � �����������
Matrix::Matrix(int new_width, int new_height, int* coefs)
{ 
	count++; 

	height = new_height;
	width = new_width;

	coef = new int[height * width];

	for(int i = 0; i < width * height; i++)
		coef[i] = coefs[i];
}

// ����������
Matrix::~Matrix()
{
	count--; 
	delete[] coef;
}


// int Matrix::get_count()
// ���������� ���������� ��������-������
// return - ���-�� ��������� ��������-������, int
int Matrix::get_count() {
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

	for(int i = 0; i < width * height; i++)
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
	if(x < 0 || x > width - 1 || y < 0 || y > height - 1)
		return 0;

	return coef[y * width + x];
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
	if(x < 0 || x > width - 1 || y < 0 || y > height - 1)
		return false;

	coef[y * width + x] = new_coef;
	return true;
}

// void Matrix.find_coeff()
// ����� ������������ �������
// args:
// - int coef_to_find - �����������, ������� �������� ���� �����
// - int *x - ��������� �� int, � ������� ������� �������� ����� ������� ���������� ������������ (-1 ���� �� ������)
// - int *y - ��������� �� int, � ������� ������� �������� ����� ������ ���������� ������������ (-1 ���� �� ������)
void Matrix::find_coeff(int coef_to_find, int *x, int *y)
{
	int result_x = -1;
	int result_y = -1;

	for(int i = 0; i < width * height; i++)
		if(coef[i] == coef_to_find)
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
	for(int x = 0; x < width; x++)
	{
		for(int cur_step = 0; cur_step < height; cur_step++)
		{
			int min = INT_MAX;
			int min_id = -1;

			for(int y = cur_step; y < height; y++)
			{
				if(coef[y * width + x] < min)
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
	for(int y = 0; y < height; y++)
	{
		for(int cur_step = 0; cur_step < width; cur_step++)
		{
			int min = INT_MAX;
			int min_id = -1;

			for(int x = cur_step; x < width; x++)
			{
				if(coef[y * width + x] < min)
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
void Matrix::print() 
{
	std::cout << "Matrix " << width << "x" << height << ":" << std::endl;

	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
			std::cout << coef[y * width + x] << ' ';

		std::cout << std::endl;
	}
}

// char* Matrix.to_string()
// ��������� ������� ���������� �������������
// return - ������ � ����������� � �������
char* Matrix::to_string()
{
	char result[1024];
	
	// itoa maybe?
	strcpy(result, width + "0");
	strcpy(result, "x");
	strcpy(result, height + "0");
	strcpy(result, "\n");
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			strcpy(result, coef[y * width + x] + "0");
			strcpy(result, " ");
		}

		strcpy(result, "\n");
	}

	return result;
}
