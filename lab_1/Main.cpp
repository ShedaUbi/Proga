#include "Matrix.h"
#include "Test.h"
#include <iostream>

using namespace std;

void do_tests()
{
	Test test;
	
	if(test.test_change_coeff())
		cout << "Change coefficient test: True" << endl;
	else
		cout << "Change coefficient test: False" << endl;
	
	if(test.test_change_coeff_invalid_pos())
		cout << "Change coefficient in invalid position test: True" << endl;
	else
		cout << "Change coefficient in invalid position test: False" << endl;
	
	if(test.test_find_existing_coeff())
		cout << "Find existing coefficient test: True" << endl;
	else
		cout << "Find existing coefficient test: False" << endl;
	
	if(test.test_find_nonexisting_coeff())
		cout << "Find non-existing coefficient test: True" << endl;
	else
		cout << "Find non-existing coefficient test: False" << endl;
	
	if(test.test_sort_lines())
		cout << "Sort lines test: True" << endl;
	else
		cout << "Sort lines test: False" << endl;

	if(test.test_sort_columns())
		cout << "Sort columns test: True" << endl;
	else
		cout << "Sort columns test: False" << endl;
}

void input_output_check()
{
	Matrix* test_matrix = new Matrix(2, 3);
	cout << "Enter coefficients of 2x3 matrix:" << endl;
	test_matrix->input_coeffs();
	test_matrix->print();
}

int main() {
	do_tests();
	input_output_check();

	cin.get();
}