#include <iostream>
using namespace std;

int fibbo(int n) {

	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	else {
		return fibbo(n - 1) + fibbo(n - 2);
	}
}

//����Լ� : ���������� ���� �ɶ����� �ݺ������� �����θ� �ҷ����� �־��� �۾��� ����
int factorial(int n) {
	
	if (n == 0) {
	//�������� 
		return 1;
	}
	else {
	//���������� �������� �ʾ����Ƿ� �ݺ������� �����θ� �ҷ���
		return n * factorial(n - 1);
	}
}

int array_sum(int array [10] , int size) {

	static int sum = 0;
	//���������̹Ƿ� �Լ������ �ʱ�ȭ�� �ƴ� �� ���� ��� ������ ����

	if (size == -1) {
		return sum;
	}
	else
	{
		sum = sum + array[size];
		return array_sum(array, size - 1);
	}
}

void fibbo_print(int n) {
	int* print_array = (int*)malloc(sizeof(int) * n);
	int i = 1;

	while (i < n+1)
	{
		print_array[i - 1] = fibbo(i);
		i = i + 1;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", print_array[i]);
	}
	printf("\n");
}


int main() {
	cout << "Recursive_Function" <<endl;
	int i;
	scanf_s("%d",&i);
	int result_fibbo = fibbo(i);
	int result_factorial = factorial(i);
	cout <<i<<" factorial = " << result_factorial << endl;
	cout << i << "��° fibbonaci ������ " << result_fibbo << endl;
	fibbo_print(i);

	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int result_sum = array_sum(array, sizeof(array) / sizeof(int) -1);
	
	cout << result_sum << endl;

	return 0;
}