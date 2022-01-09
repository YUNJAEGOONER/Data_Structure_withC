#include <iostream>
using namespace std;

void Bubble_Sort(int array[5],int size) {

	for (int i = 0; i < size - 1 ; i++) {
		for (int j = 0; j < size - 1 -i; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j+1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}

	for (int i = 0; i < size ; i++) {
		cout << array[i]<<" ";
	}
}

int main() {
	cout<<"Bubble_Sort"<<endl;
	int array[5] = { 22, 51, 17, 55, 1 };
	Bubble_Sort(array,sizeof(array)/sizeof(int));
}
