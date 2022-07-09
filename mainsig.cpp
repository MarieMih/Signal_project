#include<cassert>
#include<iostream>

#define TEST1 5
#define TEST2 4

#include "digit_sig.h"

void manual_test()
{
	digit_sig test1, test2;
		
	int a_test3[] = { 0, 1, 2, 3, 4 };
	int a_test4[] = { 5, 1, 2, 3, 4 };
	digit_sig test3 (a_test3, 5), test4(a_test4, 5);
	
	assert(!test1.get_size_array());

	test1.input_r(TEST1);
	test1.print();
	test2.input_r(TEST2);
	test2.print();

	test1.concat(test2);
	test1.print();
	assert(test1.get_size_array() == (TEST1 + TEST2) || (MAX_SIZE));
		//��������� ����� �� ������� ������������� ������� �������

	test1.concat(test2);
		//������ �� ���� ��������� ������ ���������
	assert(test1.get_size_array() == (TEST1 + TEST2) || (MAX_SIZE)); 
	test1.print();

	assert(test1(MAX_SIZE*RAND_MAX+1) < 0); //����� ��������� ����� �������
	assert(test1(-3) < 0);
	assert(test3(0) && test3(1));
	assert(!test4(0) && test4(6));
}

int main () {
	manual_test();
	return 0;
}