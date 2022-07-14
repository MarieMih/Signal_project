#ifndef DIGIT_SIG_HEADER
#define DIGIT_SIG_HEADER


#include <vector>
using namespace std;

class DigitSig {
	unsigned int id; //����� ����������� ������� ������� �������������, ��������, �������������� �����
	double down_level[2] = { 0.0, 0.8 }; //�������� "�������� ����������", ������� ������������� ������� ������
	double up_level[2] = { 3.5, 5.0 };
	vector <unsigned int> arr; //������, � ������� ������������ ������������ �������, ������� � ������� ������
public:
	DigitSig () {}
	DigitSig (int name) : id(name) {}
	DigitSig(const vector <unsigned int> mass) { arr = mass; };

	void input_r (int x); //���������� ������� ���������� ������� � ����������� ������� �
	void print() const;
	size_t get_size_array() const;

	int operator ()(unsigned int) const; //���������� �������� ������� � ����� ������ �������
	DigitSig& concat(const DigitSig&); //������������ � ������ ������� ������
};
#endif