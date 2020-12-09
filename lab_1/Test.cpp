#include "Matrix.h"
#include "IdentityMatrix.h"
#include "TriMatrix.h"

#include "Test.h"

#include <iostream>
#include <fstream>

// Конструктор по умолчанию
Test::Test() {}

// Matrix* Test.test_get_test_matrix()
// Возвращает тестовую матрицу 3х3 с пре-назначенными значениями
// return - как в описании.
Matrix* Test::test_get_test_matrix()
{
	int* test_coefs = new int[9];
	test_coefs[0] = 3; test_coefs[1] = 2; test_coefs[2] = 1;
	test_coefs[3] = 9; test_coefs[4] = 8; test_coefs[5] = 7;
	test_coefs[6] = 6; test_coefs[7] = 5; test_coefs[8] = 4;

	return new Matrix(3, 3, test_coefs);
}

// bool Test::test_saveload_operators()
// Тестирование сохранения и загрузки матрицы в файл
// return - true, если тест пройден
bool Test::test_saveload_operators()
{
	Matrix::clear_file();

	std::ofstream ofs = Matrix::open_file_save();
	if (!ofs) return false;

	Matrix* test_mtrx1 = this->test_get_test_matrix();

	ofs << *test_mtrx1;
	ofs.close();

	std::ifstream ifs = Matrix::open_file_load();
	if (!ifs) return false;

	Matrix* test_mtrx2 = new Matrix();

	ifs >> *test_mtrx2;
	ifs.close();

	for (int y = 0; y < test_mtrx1->get_h(); y++)
		for (int x = 0; x < test_mtrx1->get_w(); x++)
			if (test_mtrx1->get_coef(x, y) != test_mtrx2->get_coef(x, y))
				return false;

	return true;
}

// bool Test::test_saveload_bin_operators()
// Тестирование сохранения и загрузки матрицы в бинарный файл
// return - true, если тест пройден
bool Test::test_saveload_bin_operators()
{
	Matrix::clear_bin_file();

	std::ofstream ofs = Matrix::open_file_save_bin();
	if (!ofs) return false;

	Matrix* test_mtrx1 = this->test_get_test_matrix();

	ofs << *test_mtrx1;
	ofs.close();

	std::ifstream ifs = Matrix::open_file_load_bin();
	if (!ifs) return false;

	Matrix* test_mtrx2 = new Matrix();

	ifs >> *test_mtrx2;
	ifs.close();

	for (int y = 0; y < test_mtrx1->get_h(); y++)
		for (int x = 0; x < test_mtrx1->get_w(); x++)
			if (test_mtrx1->get_coef(x, y) != test_mtrx2->get_coef(x, y))
				return false;

	return true;
}

// bool Test::test_identity_matrix()
// Тестирование создания и заполнения единичной матрицы
// return - true, если тест пройден
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

	return true;
}

// bool Test::test_triangle_matrix()
// Тестирование создания и заполнения треугольной матрицы
// return - true, если тест пройден
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

	return true;
}


// bool Test::test_try_constructor()
// Тестирования конструкции try-catch в конструкторе класса
// return - true, если тест пройден
bool Test::test_try_constructor()
{
	Matrix* matrix1 = new Matrix(-1, -1);

	int* invalid_arr = new int[5];
	invalid_arr[0] = (int)nullptr;
	Matrix* matrix2 = new Matrix(3, 3, invalid_arr);

	return true;
}

// bool Test::test_try_get_coef()
// Тестирования конструкции try-catch в методе получения значения коэффициента матрицы
// return - true, если тест пройден
bool Test::test_try_get_coef()
{
	Matrix* matrix = this->test_get_test_matrix();
	return matrix->get_coef(-1, -1) == -1;
}

// bool Test::test_try_set_coef()
// Тестирования конструкции try-catch в методе установки значения коэффициента матрицы
// return - true, если тест пройден
bool Test::test_try_set_coef()
{
	Matrix* matrix = this->test_get_test_matrix();
	return !matrix->change_coeff(-1, -1, -1);
}
