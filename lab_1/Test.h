#pragma once
#include "Matrix.h"

struct Test {
	Test();

	Matrix* test_get_test_matrix();

	bool test_saveload_operators();
	bool test_saveload_bin_operators();
	bool test_saveload_operators_mult();

	bool test_identity_matrix();
	bool test_triangle_matrix();

	bool test_try_constructor();
	bool test_try_get_coef();
	bool test_try_set_coef();
};