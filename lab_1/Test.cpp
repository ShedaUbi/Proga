#include "Matrix.h"
#include "IdentityMatrix.h"
#include "TriMatrix.h"

#include "Test.h"

#include <iostream>
#include <fstream>
#include <ctime>

// ����������� �� ���������
Test::Test() {}

// Matrix* Test.test_get_test_matrix()
// ���������� �������� ������� 3�3 � ���-������������ ����������
// return - ��� � ��������.
Matrix* Test::test_get_test_matrix()
{
	int* test_coefs = new int[9];
	test_coefs[0] = 3; test_coefs[1] = 2; test_coefs[2] = 1;
	test_coefs[3] = 9; test_coefs[4] = 8; test_coefs[5] = 7;
	test_coefs[6] = 6; test_coefs[7] = 5; test_coefs[8] = 4;

	return new Matrix(3, 3, test_coefs);
}

// bool Test::test_saveload_operators_mult()
// ������������ ���������� � �������� ���������� ��������� ������ � ����
// return - true, ���� ���� �������
bool Test::test_saveload_operators_mult()
{
	srand(time(0));
	std::ofstream ofs("cache_mult.txt", std::ios::out);

	if (!ofs)
	{
		std::cerr << "Error: unable to write to cache_mult.txt" << std::endl;
		return false;
	}

	const int mtx_count = 10;
	Matrix* mtx_array[mtx_count];

	for (int k = 0; k < mtx_count; k++)
	{
		int width = rand() % 10 + 2;
		int height = rand() % 10 + 2;

		int* coefs = new int[width * height];

		for (int tc = 0; tc < width * height; tc++)
			coefs[tc] = rand() % 256 + 1;

		mtx_array[k] = new Matrix(width, height, coefs);

		//std::cout << *mtx_array[k] << std::endl;
		ofs << *mtx_array[k];
	}

	ofs.close();

	std::ifstream ifs("cache_mult.txt", std::ios::in);

	if (!ifs)
	{
		std::cerr << "Error: unable to read from cache_mult.txt" << std::endl;
		return false;
	}

	int cur_mtx = 0;
	while (true)
	{
		Matrix* test_mtrx2 = new Matrix();
		ifs >> *test_mtrx2;

		if (ifs.peek() == EOF)
			break;

		Matrix* temp_mtx = mtx_array[cur_mtx];

		for (int y = 0; y < temp_mtx->get_h(); y++)
			for (int x = 0; x < temp_mtx->get_w(); x++)
				if (temp_mtx->get_coef(x, y) != test_mtrx2->get_coef(x, y))
					return false;

		cur_mtx++;
		delete test_mtrx2;
	}

	ifs.close();

	for (int k = 0; k < mtx_count; k++)
		delete mtx_array[k];

	return cur_mtx == mtx_count;
}

// bool Test::test_saveload_operators()
// ������������ ���������� � �������� ������� � ����
// return - true, ���� ���� �������
bool Test::test_saveload_operators()
{
	std::ofstream ofs("cache.txt", std::ios::out);

	if (!ofs)
	{
		std::cerr << "Error: unable to write to cache.txt" << std::endl;
		return false;
	}

	Matrix* test_mtrx1 = this->test_get_test_matrix();

	ofs << *test_mtrx1;
	ofs.close();

	std::ifstream ifs("cache.txt", std::ios::in);

	if (!ifs)
	{
		std::cerr << "Error: unable to read from cache.txt" << std::endl;
		return false;
	}

	Matrix* test_mtrx2 = new Matrix();

	ifs >> *test_mtrx2;
	ifs.close();

	for (int y = 0; y < test_mtrx1->get_h(); y++)
		for (int x = 0; x < test_mtrx1->get_w(); x++)
			if (test_mtrx1->get_coef(x, y) != test_mtrx2->get_coef(x, y))
				return false;

	delete test_mtrx1;
	delete test_mtrx2;

	return true;
}

// bool Test::test_saveload_bin_operators()
// ������������ ���������� � �������� ������� � �������� ����
// return - true, ���� ���� �������
bool Test::test_saveload_bin_operators()
{
	std::ofstream ofs("cache.dat", std::ios::binary | std::ios::out);

	Matrix* test_mtrx1 = this->test_get_test_matrix();

	ofs << *test_mtrx1;
	ofs.close();

	std::ifstream ifs("cache.dat", std::ios::binary | std::ios::in);
	if (!ifs)
	{
		std::cerr << "Error: unable to read from cache.dat" << std::endl;
		return false;
	}

	Matrix* test_mtrx2 = new Matrix();

	ifs >> *test_mtrx2;
	ifs.close();

	for (int y = 0; y < test_mtrx1->get_h(); y++)
		for (int x = 0; x < test_mtrx1->get_w(); x++)
			if (test_mtrx1->get_coef(x, y) != test_mtrx2->get_coef(x, y))
				return false;

	delete test_mtrx1;
	delete test_mtrx2;

	return true;
}

// bool Test::test_identity_matrix()
// ������������ �������� � ���������� ��������� �������
// return - true, ���� ���� �������
bool Test::test_identity_matrix()
{
	int* test_coefs = new int[9];
	test_coefs[0] = 3; test_coefs[1] = 2; test_coefs[2] = 1;
	test_coefs[3] = 9; test_coefs[4] = 8; test_coefs[5] = 7;
	test_coefs[6] = 6; test_coefs[7] = 5; test_coefs[8] = 4;

	int* test_coefs_real = new int[9];
	test_coefs_real[0] = 1; test_coefs_real[1] = 0; test_coefs_real[2] = 0;
	test_coefs_real[3] = 0; test_coefs_real[4] = 1; test_coefs_real[5] = 0;
	test_coefs_real[6] = 0; test_coefs_real[7] = 0; test_coefs_real[8] = 1;

	IdentityMatrix* ident_matrix = new IdentityMatrix(3, 3, test_coefs);

	for (int y = 0; y < ident_matrix->get_h(); y++)
		for (int x = 0; x < ident_matrix->get_w(); x++)
			if (ident_matrix->get_coef(x, y) != test_coefs_real[x + y * ident_matrix->get_w()])
				return false;

	delete ident_matrix;

	return true;
}

// bool Test::test_triangle_matrix()
// ������������ �������� � ���������� ����������� �������
// return - true, ���� ���� �������
bool Test::test_triangle_matrix()
{
	int* test_coefs = new int[9];
	test_coefs[0] = 3; test_coefs[1] = 2; test_coefs[2] = 1;
	test_coefs[3] = 9; test_coefs[4] = 8; test_coefs[5] = 7;
	test_coefs[6] = 6; test_coefs[7] = 5; test_coefs[8] = 4;

	int* test_coefs_real = new int[9];
	test_coefs_real[0] = 3; test_coefs_real[1] = 0; test_coefs_real[2] = 0;
	test_coefs_real[3] = 9; test_coefs_real[4] = 8; test_coefs_real[5] = 0;
	test_coefs_real[6] = 6; test_coefs_real[7] = 5; test_coefs_real[8] = 4;

	TriMatrix* tri_matrix = new TriMatrix(3, 3, test_coefs, false);

	for (int y = 0; y < tri_matrix->get_h(); y++)
		for (int x = 0; x < tri_matrix->get_w(); x++)
			if (tri_matrix->get_coef(x, y) != test_coefs_real[x + y * tri_matrix->get_w()])
				return false;

	delete tri_matrix;

	return true;
}


// bool Test::test_try_constructor()
// ������������ ����������� try-catch � ������������ ������
// return - true, ���� ���� �������
bool Test::test_try_constructor()
{
	Matrix* matrix1 = new Matrix(-1, -1);

	int* invalid_arr = new int[5];
	invalid_arr[0] = (int)nullptr;
	Matrix* matrix2 = new Matrix(3, 3, invalid_arr);

	delete matrix1;
	delete matrix2;

	return true;
}

// bool Test::test_try_get_coef()
// ������������ ����������� try-catch � ������ ��������� �������� ������������ �������
// return - true, ���� ���� �������
bool Test::test_try_get_coef()
{
	return this->test_get_test_matrix()->get_coef(-1, -1) == -1;
}

// bool Test::test_try_set_coef()
// ������������ ����������� try-catch � ������ ��������� �������� ������������ �������
// return - true, ���� ���� �������
bool Test::test_try_set_coef()
{
	return !this->test_get_test_matrix()->change_coeff(-1, -1, -1);
}
