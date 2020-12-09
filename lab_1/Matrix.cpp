#define _CRT_SECURE_NO_WARNINGS
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <cstring>

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
	try
	{	
		if (new_width <= 0 || new_height <= 0) 
			throw -1;

		count++;

		height = new_height;
		width = new_width;

		coef = new int[height * width];

		for (int i = 0; i < width * height; i++)
			coef[i] = 0;
	}
	catch(int e)
	{
		std::cout << "Error: Invalid matrix size!" << std::endl;
	}
}

// Конструктор с параметрами
Matrix::Matrix(int new_width, int new_height, int* coefs)
{	
	try
	{
		if (new_width <= 0 || new_height <= 0) 
			throw -1;

		count++;

		height = new_height;
		width = new_width;

		coef = new int[height * width];

		for (int i = 0; i < width * height; i++)
		{
			if (!coefs[i])
				throw -2;
			else
				coef[i] = coefs[i];
		}
	}
	catch (int e)
	{
		std::cout << (e == -1 ? "Error: Invalid matrix size!" : "Error: Invalid input coefficents!") << std::endl;
	}
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
int Matrix::get_count() 
{
	return count;
}

// void Matrix::clear_file()
// Очищает файл сохранения
// return - void
void Matrix::clear_file() 
{
	std::ofstream ofs("cache.txt", std::ios::out);

	if (!ofs) 
		std::cerr << "Error: unable to write to cache.txt" << std::endl;

	else
	{
		ofs << "";
		ofs.close();
	}
}

// void Matrix::clear_bin_file()
// Очищает бинарный файл сохранения
// return - void
void Matrix::clear_bin_file()
{
	std::ofstream ofs("cache.dat", std::ios::binary | std::ios::out);

	if (!ofs) 
		std::cerr << "Error: unable to write to cache.dat" << std::endl;

	else
	{
		ofs << "";
		ofs.close();
	}
}

// ofstream Matrix::open_file_save()
// Открывает файл сохранения для записи в конец
// return - ofstream
std::ofstream Matrix::open_file_save()
{
	std::ofstream ofs("cache.txt", std::ios::app);

	if (!ofs) 
		std::cerr << "Error: unable to write to cache.txt" << std::endl;
	
	return ofs;
}

// ifstream Matrix::open_file_load()
// Открывает файл сохранения для загрузки объектов
// return - ifstream
std::ifstream Matrix::open_file_load() 
{
	std::ifstream ifs("cache.txt", std::ios::in);

	if (!ifs)
		std::cerr << "Error: unable to read from cache.txt" << std::endl;
	
	return ifs;
}

// ofstream Matrix::open_file_save_bin()
// Открывает бинарный файл сохранения для записи в конец
// return - ofstream
std::ofstream Matrix::open_file_save_bin()
{
	std::ofstream ofs("cache.dat", std::ios::binary | std::ios::app);

	if (!ofs) 
		std::cerr << "Error: unable to write to cache.dat" << std::endl;
	
	return ofs;
}

// ifstream Matrix::open_file_load_bin()
// Открывает бинарный файл сохранения для загрузки объектов
// return - ifstream
std::ifstream Matrix::open_file_load_bin()
{
	std::ifstream ifs("cache.dat", std::ios::binary | std::ios::in);

	if (!ifs)
		std::cerr << "Error: unable to read from cache.dat" << std::endl;
	
	return ifs;
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

	for (int i = 0; i < width * height; i++)
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
	try {
		if (x < 0 || x > width - 1 || y < 0 || y > height - 1)
			throw -1;

		return coef[y * width + x];
	}
	catch (int e)
	{
		std::cout << "Error: Invalid coefficent coordinates!" << std::endl;
		return -1;
	}
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
	try {
		if (x < 0 || x > width - 1 || y < 0 || y > height - 1)
			throw -1;

		coef[y * width + x] = new_coef;
		return true;
	}
	catch (int e)
	{
		std::cout << "Error: Invalid coefficent coordinates!" << std::endl;
		return false;
	}
}

// void Matrix.find_coeff()
// Поиск коэффициента матрицы
// args:
// - int coef_to_find - коэффициент, позицию которого надо найти
// - int *x - указатель на int, в который следует записать номер столбца найденного коэффициента (-1 если не найден)
// - int *y - указатель на int, в который следует записать номер строки найденного коэффициента (-1 если не найден)
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
// Сортировка столбцов матрицы
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
// Сортировка строк матрицы
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
// Вывод матрицы в консоль
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

// Matrix* Matrix::operator+(Matrix b)
// Перегрузка оператора сложения матриц
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
// Перегрузка оператора вычитания матриц
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
// Перегрузка оператора индексирования матрицы
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
// Перегрузка оператора вызова матрицы как функции
void Matrix::operator()(int x, int y, int new_coef)
{
	change_coeff(x, y, new_coef);
}

// Matrix& Matrix::operator=(Matrix& m2)
// Перегрузка оператора присваивания матриц
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
// Перегрузка оператора записи в поток
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
// Перегрузка оператора записи из потока
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
// Перегрузка оператора записи из файлового потока
std::ofstream& operator<<(std::ofstream& os, Matrix& p) 
{
	os << p.get_w() << ' ' << p.get_h() << ' ';

	for (int y = 0; y < p.get_h(); y++)
		for (int x = 0; x < p.get_w(); x++)
			os << p.get_coef(x, y) << ' ';

	return os;
}

// std::ifstream& operator>>(std::ifstream& is, Matrix& p)
// Перегрузка оператора записи в файловый поток
std::ifstream& operator>>(std::ifstream& is, Matrix& p)
{
	is >> p.width >> p.height;

	delete[] p.coef;
	p.coef = new int[p.height * p.width];

	for (int i = 0; i < p.height * p.width; i++)
		is >> p.coef[i];
	
	return is;
}