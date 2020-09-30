#include "Matrix.h"
#include "Test.h"
#include <iostream>

// Конструктор по умолчанию
Test::Test() {}

// Matrix* Test.test_get_test_matrix()
// Возвращает тестовую матрицу 3х3 с пре-назначенными значениями
// return - как в описании.
Matrix* Test::test_get_test_matrix()
{
	int* test_coefs = new int[9];
	test_coefs[0] = 3;
	test_coefs[1] = 2;
	test_coefs[2] = 1;

	test_coefs[3] = 9;
	test_coefs[4] = 8;
	test_coefs[5] = 7;

	test_coefs[6] = 6;
	test_coefs[7] = 5;
	test_coefs[8] = 4;

	return new Matrix(3, 3, test_coefs);
}

// bool Test.test_change_coeff()
// Проверяет работоспособность функции change_coeff на валидных данных
// return - true, если коэффициент был заменен успешно - false иначе.
bool Test::test_change_coeff()
{
	Matrix* test_mtrx = test_get_test_matrix();

	test_mtrx->change_coeff(1, 1, 10);
	return test_mtrx->get_coef(1, 1) == 10;
}

// bool Test.test_change_coeff()
// Проверяет работоспособность функции change_coeff на невалидных данных
// return - true, если change_coeff заметила подвох - false иначе.
bool Test::test_change_coeff_invalid_pos()
{
	Matrix* test_mtrx = test_get_test_matrix();
	return !test_mtrx->change_coeff(-1, -1, 10);
}

// bool Test.test_find_existing_coeff()
// Проверяет работоспособность функции find_coeff на валидных данных
// return - true, если коэффициент был найден в предполагаемой позиции - false иначе.
bool Test::test_find_existing_coeff()
{
	Matrix* test_mtrx = test_get_test_matrix();

	int x, y;
	test_mtrx->find_coeff(4, &x, &y);

	return (x == 2) && (y == 2);
}

// bool Test.test_find_nonexisting_coeff()
// Проверяет работоспособность функции find_coeff на невалидных данных
// return - true, если find_coeff заметила подвох - false иначе.
bool Test::test_find_nonexisting_coeff()
{
	Matrix* test_mtrx = test_get_test_matrix();

	int x, y;
	test_mtrx->find_coeff(100, &x, &y);

	return (x == -1) && (y == -1);
}

// bool Test.test_sort_lines()
// Проверяет работоспособность функции sort_lines на валидных данных
// return - true, если строки были отсортированы успешно - false иначе.
bool Test::test_sort_lines()
{
	Matrix* test_mtrx1 = test_get_test_matrix();
	test_mtrx1->sort_lines();
	
	int* test_coefs = new int[9];
	test_coefs[0] = 1;
	test_coefs[1] = 2;
	test_coefs[2] = 3;

	test_coefs[3] = 7;
	test_coefs[4] = 8;
	test_coefs[5] = 9;

	test_coefs[6] = 4;
	test_coefs[7] = 5;
	test_coefs[8] = 6;
	
	for(int y = 0; y < test_mtrx1->get_h(); y++)
		for(int x = 0; x < test_mtrx1->get_w(); x++)
			if(test_coefs[y * test_mtrx1->get_w() + x] != test_mtrx1->get_coef(x, y))
				return false;

	return true;
}

// bool Test.test_sort_columns()
// Проверяет работоспособность функции sort_columns на валидных данных
// return - true, если столбцы были отсортированы успешно - false иначе.
bool Test::test_sort_columns()
{
	Matrix* test_mtrx1 = test_get_test_matrix();
	test_mtrx1->sort_columns();
	
	int* test_coefs = new int[9];
	test_coefs[0] = 3;
	test_coefs[1] = 2;
	test_coefs[2] = 1;

	test_coefs[3] = 6;
	test_coefs[4] = 5;
	test_coefs[5] = 4;

	test_coefs[6] = 9;
	test_coefs[7] = 8;
	test_coefs[8] = 7;
	
	for(int y = 0; y < test_mtrx1->get_h(); y++)
		for(int x = 0; x < test_mtrx1->get_w(); x++)
			if(test_coefs[y * test_mtrx1->get_w() + x] != test_mtrx1->get_coef(x, y))
				return false;

	return true;
}