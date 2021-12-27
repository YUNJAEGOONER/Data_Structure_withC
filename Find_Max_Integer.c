#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void print_array(int arr[10], int N) {

	//�Լ��� �̸��� print_array�̰�
	//ũ�Ⱑ 10�� ���� �迭��, ������ �Ķ���ͷ� ������
	//Return Type�� ���� �Լ�

	printf("������ �迭�� ");
	for (int j = 0; j < 10; j++) {
		printf("%d ", arr[j]);
	}
	printf("\n");
}

int Find_Max(int arr[10], int N) {
	//�Լ��� �̸��� Find_Max�̰�
	//ũ�Ⱑ 10�� ���� �迭��, ������ �Ķ���ͷ� ������
	//Return Type�� ������ �Լ�

	int max = arr[0];

	for (int i = 1; i < N; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	return max;
}

void even_odd(int arr[10], int N) {
	//�Լ��� �̸��� even_odd�̰�
	//ũ�Ⱑ 10�� ���� �迭��, ������ �Ķ���ͷ� ������
	//Return Type�� ���� �Լ�
	int odd = 0;
	int even = 0;
	int i = 0;
	while (i < N) {
		if (arr[i] % 2 == 0) {
			odd = odd + arr[i];
		}
		else {
			even = even + arr[i];
		}
		i = i + 1;
	}
	printf("�迭���� Ȧ���� ���� %d, ¦���� ���� %d\n", even, odd);
}

void even_odd_pointer(int arr[10], int N, int *even_sum, int *odd_sum) {
	
	//�Լ��� ����� Ȧ���� ��, ¦���� ���ε� 2���� �����͸� ���� ���ϹǷ� Pointer���� ���
	//�Լ��� �̸��� even_odd�̰�
	//ũ�Ⱑ 10�� ���� �迭��, ������ �Ķ���ͷ� ������
	//Return Type�� ���� �Լ�

	int i = 0;
	while (i < N) {
		if (arr[i] % 2 == 0) {
			*odd_sum = *odd_sum + arr[i];
		}
		else {
			*even_sum = *even_sum + arr[i];
		}
		i = i + 1;
	}

}

void main() {
	srand((unsigned)time(NULL)); 
	//�ð� �Լ��� �̿��� ���� ���
	
	int arr [10];
	int max = 0;

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 30 + 1;
		// %30�� �ϰ� �Ǹ� ����� (0 ~ 29)
		// +1�� ���� 1 ~ 30������ ���ڸ� �������� ����
	}

	print_array(arr, 10);
	max = Find_Max(arr, 10);
	printf("�迭���� ���� ū �� : %d\n", max);
	even_odd(arr, 10);

	int *even_sum = 0;
	int *odd_sum = 0;

	even_odd_pointer(arr, 10, &even_sum, &odd_sum);
	//�Ű������� ������ �����̹Ƿ� ������ ������ �ּҸ� �Ѱ��־���Ѵ�

	printf("�迭���� Ȧ���� ���� %d, ¦���� ���� %d\n", even_sum, odd_sum);
}
