#ifndef DIGIT_SIG_HEADER
#define DIGIT_SIG_HEADER
#define MAX_SIZE 12

using namespace std;

class digit_sig {
	int id; //����� ����������� ������� ������� �������������, ��������, �������������� �����
	double down_level[2] = { 0.0, 0.8 }; //�������� "�������� ����������", ������� ������������� ������� ������
	double up_level[2] = { 3.5, 5.0 };
	int array[MAX_SIZE]; //������, � ������� ������������ ������������ �������, ������� � ������� ������
	int size_array; //�������� ����� ������� �������
public:
	digit_sig() { size_array = 0; }
	digit_sig(int name) : id(name) { size_array = 0; }
	digit_sig(int*, int);

	void input_r (int x); //���������� ������� ���������� ������� � ����������� ������� �
	void print();
	int get_size_array();

	int operator ()(int) const; //���������� �������� ������� � ����� ������ �������
	digit_sig& concat(const digit_sig&); //������������ � ������ ������� ������
};
#endif