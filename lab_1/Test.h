#pragma once
#include "Matrix.h"

struct Test { 
	Test();

	Matrix* test_get_test_matrix();
	
	bool test_change_coeff();
	bool test_change_coeff_invalid_pos();
	bool test_find_existing_coeff();
	bool test_find_nonexisting_coeff();
	bool test_sort_lines();
	bool test_sort_columns();
};