#include<cassert>
#include<iostream>

#define TEST1 5
#define TEST2 4
#define MAX_SIZE 12

#include "DigitSig.h"

void manual_test()
{
	DigitSig test1, test2;
		
	vector <unsigned int> a_test3 = { 0, 1, 2, 3, 4 };
	vector <unsigned int> a_test4 = { 5, 1, 2, 3, 4 };
	DigitSig test3(a_test3), test4(a_test4);
	
	assert(!test1.get_size_array());

	test1.input_r(TEST1);
	test1.print();
	test2.input_r(TEST2);
	test2.print();

	test1.concat(test2);
	test1.print();
	assert(test1.get_size_array() == (TEST1 + TEST2));
		//проверяем выход за пределы максимального размера массива

	test1.print();

	test3.print();
	test4.print();

	assert(test1(MAX_SIZE*RAND_MAX+1) < 0); //время превышает длину сигнала
	assert(test1(-3) < 0);
	assert(test3(0) && test3(1));
	assert(!test4(0) && test4(6));
}

int main () {
	srand(5);
	manual_test();
	return 0;
}