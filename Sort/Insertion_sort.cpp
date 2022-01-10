#include<iostream>
using namespace std;

void Insertion_Sort_for(int array[5], int size) {
	for (int i = 1; i < size; i++) {
		int temp = array[i];
		for (int j = i - 1; j > -1; j--) {
			if (temp < array[j]) {
				array[j + 1] = array[j];
				array[j] = temp;
			
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void Insertion_Sort_while(int array[5], int size) {

	for (int i = 1; i < size; i++) {
		int temp = array[i];
		int j = i - 1;
		while (temp < array[j])
		{
			array[j + 1] = array[j];
			array[j] = temp;
			j = j - 1;
		}
		//이미 정렬되어 있는 배열이 오는 경우 while에서 한번도 안걸림
		//위 for문만 돌면 되므로 BestCase의 경우 시간복잡도는 Big O (n) 	
	}

	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}

}

int main() {
	cout << "Insertion Sort" << endl;
	int array[5] = { 51, 22, 17, 55, 1 };
	Insertion_Sort_for(array, sizeof(array) / sizeof(int));
	int array_1[5] = { 1, 2, 3, 4, 5};
	Insertion_Sort_while(array_1, sizeof(array_1) / sizeof(int));
}