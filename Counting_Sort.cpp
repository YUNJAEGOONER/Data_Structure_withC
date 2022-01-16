#include <iostream>
using namespace std;

//Counting_Sort(계수정렬)
//n개의 정수를 정렬 ( 단, n 은 0 ~ k )

int find_max(int * array, int size) {

	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (*(array + i) > max) {
			max = *(array + i);
		}
	}
	return max;
	// 정수의 범위인 0 ~ k 에 k 찾기
}

void count_array(int* array, int size, int* count, int max, int * count_sum) {

	for (int i = 0; i < size; i++) {
		count[array[i]] = count[array[i]] + 1;
	}
	//정렬에서 해당 Index의 수가 몇 개 인지 count하기

	for (int i = 0; i < max + 1; i++) {
		int sum = 0;
		for (int j = i; j > -1; j--) {
			sum = sum + *(count + j);
		}
		*(count_sum + i) = sum;
	}
	// index 이하의 수 개수 count
}

void sort(int* array, int size, int* count_sum, int max, int*sorted_array) {
	
	for (int i = 0; i < size; i++) {
		int index = count_sum[array[i]]-1;
		sorted_array[index] = array[i];
		count_sum[array[i]] = count_sum[array[i]] - 1;
	}
	// 정렬하기
}

int main() {
	
	cout << "Counting Sort" << endl;
	int array[8] = { 2,5,3,0,2,3,0,3 };
	int size = sizeof(array) / sizeof(int);
	int max = find_max(array ,size);

	int* count = (int*)malloc(sizeof(int) * (max+1));

	for (int i = 0; i < max + 1; i++) {
		*(count + i) = 0;
	}

	int* count_sum = (int*)malloc(sizeof(int) * (max + 1));
	count_array(array, size, count,max , count_sum);

	int* sorted_array = (int*)malloc(sizeof(int) * size);
	sort(array, size, count_sum, max, sorted_array);


	for (int i = 0; i < size; i++) {
		cout <<sorted_array[i]<<" ";
	}

	return 0;
}

