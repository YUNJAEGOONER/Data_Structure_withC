#include <iostream>
using namespace std;

//�迭�� �Ű����� ���� ��� -> �Ϲ����� �Ű����� ���� ��� 
int sum_of_array(int array[], int size) {

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + array[i];
	}
	return sum;
}

//a(�迭)�� ������ ���������� �����͸� �Ű������� ���� �� �ִ�.
float average_of_array_pointer(int * array, int size) {
	
	float sum = 0;
	float avg;
	for (int i = 0; i < size; i++) {
		sum = sum + array[i];
	}
	avg = sum / size;
	return avg;
}

int main(){

	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//������ �ڷ� 10���� ���� �� �ִ� �迭 a
	//�迭�� �̸�(a)�� �迭�� �����ּҸ� �����ϴ� ������ �����̴�.

	//a�� ������ ���������� cout << a�� �ϰ� �Ǹ� �ּҰ�, cout << *a�� �ϰԵǸ� �� �ּҿ� ����Ǿ� �ִ� ���� ���´�.
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		cout << "�ּҰ� " << a + i << "�� ������ " << *(a + i) << "�� ����Ǿ� �ִ�." << endl;
	}
	//int�� 4byte�̱� ������ �ּҰ� 4�� ���̰� ����.

	//�迭�� index�ε� ������ �����ϴ�.
	
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	int sum;;
	float avg;
	sum = sum_of_array(a, sizeof(a) / sizeof(int));
	cout << "�迭�� ���� :" << sum << endl;
	avg = average_of_array_pointer(a, sizeof(a) / sizeof(int));
	cout << "�迭�� ����� :" << avg << endl;
	return 0;
}