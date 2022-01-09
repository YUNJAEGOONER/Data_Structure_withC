#include <iostream>
using namespace std;

void Selection_Sort(int array[5], int size) {

	for (int i = 0; i < size - 1; i++) {
		int min = array[i];
		int temp = 0;
		for (int j = i + 1; j < size; j++) {
			if (min > array[j]) {
				min = array[j];
				temp = j;
			}
		}
		array[temp] = array[i];
		array[i] = min;
	}

	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}

}


int main() {
	cout << "Bubble_Sort" << endl;
	int array[5] = { 22, 51, 17, 55, 1 };
	Selection_Sort(array, sizeof(array) / sizeof(int));
}