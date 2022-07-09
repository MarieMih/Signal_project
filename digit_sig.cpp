#include <cstdlib>
#include <ctime>
#include <iostream>
#include "digit_sig.h"

digit_sig::digit_sig(int* mass, int size) {
	for (int i = 0; i < size; i++)
		array[i] = mass[i];
	size_array = size;
}

int digit_sig::operator ()(int time) const{
	if (time < 0) return -1;
	if (time == 0)
	{
		if (size_array == 0) return 0;
		else
		{
			if (array[0] != 0) return 0; //начинаем с нижнего уровня
			else return 1;
		}
	}

	int count = 0; 
	int i = 0; 
	
	while (count < time)
	{
		if (i == size_array) //время превысило длину сигнала
			return -2;
		count += array[i++];
	}
	if (--i % 2 == 0) return 0;
	return 1;
}

digit_sig& digit_sig::concat(const digit_sig& b) //присоединяет один сигнал к другому
{
	for (int i = 0; i < b.size_array; i++)
	{
		if ((size_array + i) == MAX_SIZE)
		{
			size_array = MAX_SIZE;
			break;
		}
		array[size_array + i] = b.array[i];
	}
	if (size_array != MAX_SIZE) size_array += b.size_array;
	return *this;
}

void digit_sig::input_r (int x)
{
	srand(time(nullptr));
	for (int i = 0; i < x; i++)
		array[i] = rand();
	size_array = x;
}

void digit_sig::print()
{
	for (int i = 0; i < size_array; i++)
		cout << array[i]<< " " ;
	cout << "\n";
}

int digit_sig::get_size_array()
{
	return size_array;
}