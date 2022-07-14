#include <cstdlib>
#include <ctime>
#include <iostream>
#include "DigitSig.h"

int DigitSig::operator ()(unsigned int time) const{
	if (time < 0) return -1;
	if (time == 0)
	{
		if (arr.size() == 0) return 0;
		else
		{
			if (arr[0] != 0) return 0; //начинаем с нижнего уровня
			else return 1;
		}
	}

	int count = 0; 
	int i = 0; 
	
	while (count < time)
	{
		if (i == arr.size()) //время превысило длину сигнала
			return -2;
		count += arr[i++];
	}
	if (--i % 2 == 0) return 0;
	return 1;
}

DigitSig& DigitSig::concat(const DigitSig& b) //присоединяет один сигнал к другому
{
	for (int i = 0; i < b.arr.size(); i++)
		arr.push_back(b.arr[i]);
	return *this;
}

void DigitSig::input_r (int x)
{
	for (int i = 0; i < x; i++)
		arr.push_back(rand());
}

void DigitSig::print() const
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " " ;
	cout << "\n";
}

size_t DigitSig::get_size_array() const
{
	return arr.size();
}