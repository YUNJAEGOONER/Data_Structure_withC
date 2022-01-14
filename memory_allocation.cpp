#include <iostream>
using namespace std;

void print_memory(int size,int *memory){

	for (int i = 0; i < size ; i++) {
		cout << "�ּ� �� : " << memory+i << " ���� �Ǿ� �ִ� �� : " << *(memory + i) << endl;
	}

}

int main() {
	int size = 10;
	int* memory = (int*)malloc(sizeof(int) * size);

	if (memory == NULL) {
		cout << "���� �޸� �Ҵ� ����" << endl;
	}
	else
	{
		cout << "���� �޸� �Ҵ� ����" << endl;
	}

	//malloc : �䱸�ϴ� ũ���� �޸𸮸� �Ҵ��ϰ�, �� ���� �ּҸ� ��ȯ�Ѵ�.
	//memory�� ������ ���������� cout << memory �� �� ��� �ּҰ���
	//*(memory)�� ��� �� �ּҿ� ����Ǿ� �ִ� ���� �����Եȴ�
 
	for (int i = 0; i < size / 2; i++) {
		memory[i] = i;//�迭ó�� index�ε� ������ �����ϴ�.
		cout << "�ּ� �� : " << memory+i << " ���� �Ǿ� �ִ� �� : " << memory[i] << endl;
	}

	for (int i = size/2; i < size; i++){
		*(memory + i) = i;
		//�ش� �ּ��� ���� i�� ����
		cout << "�ּ� �� : " << memory+i << " ���� �Ǿ� �ִ� �� : " << *(memory+i) << endl;
	}

	memory = (int*)realloc(memory,sizeof(int)*size*2);
	//realloc �Լ��� �̿��� �޸𸮸� �߰� �Ҵ�

	for (int i = size; i < size * 2; i++) {
		*(memory + i) = i;
		cout << "�ּ� �� : " << memory + i << " ���� �Ǿ� �ִ� �� : " << *(memory + i) << endl;
	}

	memory = (int*)realloc(memory, sizeof(int) * (size / 2));
	// realloc �Լ��� �̿��� �޸��� ũ�⸦ ���

	print_memory(size / 2, memory);

	free(memory);
	//�޸� �Ҵ� ����

	return 0;

}