#ifndef DIGIT_SIG_HEADER
#define DIGIT_SIG_HEADER
#define MAX_SIZE 12

using namespace std;

class digit_sig {
	int id; //будем присваивать каждому сигналу идентификатор, например, четырехзначный номер
	double down_level[2] = { 0.0, 0.8 }; //значение "входного напряжения", которое соответствует нижнему уровню
	double up_level[2] = { 3.5, 5.0 };
	int array[MAX_SIZE]; //массив, в который записывается длительность сигнала, начиная с нижнего уровня
	int size_array; //реальная длина массива сигнала
public:
	digit_sig() { size_array = 0; }
	digit_sig(int name) : id(name) { size_array = 0; }
	digit_sig(int*, int);

	void input_r (int x); //наполнение массива рандомными числами с присвоением размера х
	void print();
	int get_size_array();

	int operator ()(int) const; //возвращает значение сигнала в некий момент времени
	digit_sig& concat(const digit_sig&); //присоединяет к одному сигналу другой
};
#endif