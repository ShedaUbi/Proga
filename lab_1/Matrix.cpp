#define _CRT_SECURE_NO_WARNINGS
#include "Matrix.h"
#include <iostream>
#include <cstring>
//#include <stdlib.h> //for itoa

int Matrix::count = 0;

// Конструктор по умолчанию
Matrix::Matrix() 
{ 
	count++; 

	height = 1;
	width = 1;
	
	coef = new int[1];
	coef[0] = 0;
}

// Конструктор с параметрами
Matrix::Matrix(int new_width, int new_height)
{ 
	count++; 

	height = new_height;
	width = new_width;

	coef = new int[height * width];

	for(int i = 0; i < width * height; i++)
		coef[i] = 0;
}

// Конструктор с параметрами
Matrix::Matrix(int new_width, int new_height, int* coefs)
{ 
	count++; 

	height = new_height;
	width = new_width;

	coef = new int[height * width];

	for(int i = 0; i < width * height; i++)
		coef[i] = coefs[i];
}

// Деструктор
Matrix::~Matrix()
{
	count--; 
	delete[] coef;
}


// int Matrix::get_count()
// Возвращает количество обьектов-матриц
// return - кол-во созданных обьектов-матриц, int
int Matrix::get_count() {
	return count;
}


// int Matrix.get_w()
// Возвращает ширину матрицы
// return - ширина матрицы, int
int Matrix::get_w()
{
	return width;
}

// int Matrix.get_h()
// Возвращает высоту матрицы
// return - высота матрицы, int
int Matrix::get_h()
{
	return height;
}

// void Matrix.input_coeffs()
// Начинает ввод коэффициентов матрицы через консоль
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
// Возвращает коэффициент матрицы в заданной позиции
// args:
// - int x - номер столбца, коэффициент которого надо вернуть
// - int y - номер строки, коэффициент которой надо вернуть
// return - коэффициент в матрице в заданной позиции, int
int Matrix::get_coef(int x, int y)
{
	if(x < 0 || x > width - 1 || y < 0 || y > height - 1)
		return 0;

	return coef[y * width + x];
}

// bool Matrix.change_coeff(int x, int y, int new_coef)
// Заменяет коэффициент в матрице в заданной позиции
// args:
// - int x - номер столбца, в котором нужно произвести замену
// - int y - номер строки, в которой нужно произвести замену
// - int new_coef - новое значение кожффициента в заданной позиции
// return - false, если указана невалидная позиция в матрице - true иначе.
bool Matrix::change_coeff(int x, int y, int new_coef)
{
	if(x < 0 || x > width - 1 || y < 0 || y > height - 1)
		return false;

	coef[y * width + x] = new_coef;
	return true;
}

// void Matrix.find_coeff()
// Поиск коэффициента матрицы
// args:
// - int coef_to_find - коэффициент, позицию которого надо найти
// - int *x - указатель на int, в который следует записать номер столбца найденного коэффициента (-1 если не найден)
// - int *y - указатель на int, в который следует записать номер строки найденного коэффициента (-1 если не найден)
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
// Сортировка столбцов матрицы
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
// Сортировка строк матрицы
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
// Вывод матрицы в консоль
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
// Нерабочая функция строкового представления
// return - строка с информацией о матрице
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
