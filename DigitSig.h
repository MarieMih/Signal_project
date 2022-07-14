#ifndef DIGIT_SIG_HEADER
#define DIGIT_SIG_HEADER


#include <vector>
using namespace std;

class DigitSig {
	unsigned int id; //будем присваивать каждому сигналу идентификатор, например, четырехзначный номер
	double down_level[2] = { 0.0, 0.8 }; //значение "входного напряжения", которое соответствует нижнему уровню
	double up_level[2] = { 3.5, 5.0 };
	vector <unsigned int> arr; //массив, в который записывается длительность сигнала, начиная с нижнего уровня
public:
	DigitSig () {}
	DigitSig (int name) : id(name) {}
	DigitSig(const vector <unsigned int> mass) { arr = mass; };

	void input_r (int x); //наполнение массива рандомными числами с присвоением размера х
	void print() const;
	size_t get_size_array() const;

	int operator ()(unsigned int) const; //возвращает значение сигнала в некий момент времени
	DigitSig& concat(const DigitSig&); //присоединяет к одному сигналу другой
};
#endif