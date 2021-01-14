#include "Test.h"
#include <iostream>

using namespace std;

void do_tests()
{
	Test test;

	if (test.test_saveload_operators())
		cout << "Save/load operators test: True" << endl;
	else
		cout << "Save/load operators test: False" << endl;

	if (test.test_saveload_bin_operators())
		cout << "Save/load binary operators test: True" << endl;
	else
		cout << "Save/load binary operators test: False" << endl;


	if (test.test_saveload_operators_mult())
		cout << "Save/load operators for multiple objects test: True" << endl;
	else
		cout << "Save/load operators for multiple objects test: False" << endl;

	cout << endl;

	if (test.test_identity_matrix())
		cout << "Identity matrix test: True" << endl;
	else
		cout << "Identity matrix test: False" << endl;

	if (test.test_triangle_matrix())
		cout << "Triangle matrix test: True" << endl;
	else
		cout << "Triangle matrix test: False" << endl;

	cout << endl;

	if (test.test_try_constructor())
		cout << "Try-catch constructor test: True" << endl << endl;
	else
		cout << "Try-catch constructor test: False" << endl << endl;

	if (test.test_try_get_coef())
		cout << "Try-catch get coefficent test: True" << endl << endl;
	else
		cout << "Try-catch get coefficent test: False" << endl << endl;

	if (test.test_try_set_coef())
		cout << "Try-catch set coefficent test: True" << endl << endl;
	else
		cout << "Try-catch set coefficent test: False" << endl << endl;


	if (test.test_create_list())
		cout << "Create matrix list test: True" << endl << endl;
	else
		cout << "Create matrix list test: False" << endl << endl;

	if (test.test_virtualization_list())
		cout << "Matrix virtualization test: True" << endl << endl;
	else
		cout << "Matrix virtualization test: False" << endl << endl;


	if (test.test_list_native())
		cout << "Template list class test: True" << endl << endl;
	else
		cout << "Template list class test: False" << endl << endl;
}

int main() 
{
	do_tests();
	cin.get();

}