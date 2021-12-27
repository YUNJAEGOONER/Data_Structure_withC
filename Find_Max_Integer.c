#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void print_array(int arr[10], int N) {

	//함수의 이름이 print_array이고
	//크기가 10인 정수 배열과, 정수를 파라미터로 받으며
	//Return Type이 없는 함수

	printf("생성된 배열은 ");
	for (int j = 0; j < 10; j++) {
		printf("%d ", arr[j]);
	}
	printf("\n");
}

int Find_Max(int arr[10], int N) {
	//함수의 이름이 Find_Max이고
	//크기가 10인 정수 배열과, 정수를 파라미터로 받으며
	//Return Type이 정수인 함수

	int max = arr[0];

	for (int i = 1; i < N; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	return max;
}

void even_odd(int arr[10], int N) {
	//함수의 이름이 even_odd이고
	//크기가 10인 정수 배열과, 정수를 파라미터로 받으며
	//Return Type이 없는 함수
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
	printf("배열에서 홀수의 합은 %d, 짝수의 합은 %d\n", even, odd);
}

void even_odd_pointer(int arr[10], int N, int *even_sum, int *odd_sum) {
	
	//함수의 결과는 홀수의 합, 짝수의 합인데 2개의 데이터를 리턴 못하므로 Pointer개념 사용
	//함수의 이름이 even_odd이고
	//크기가 10인 정수 배열과, 정수를 파라미터로 받으며
	//Return Type이 없는 함수

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
	//시간 함수를 이용한 난수 사용
	
	int arr [10];
	int max = 0;

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 30 + 1;
		// %30을 하게 되면 결과는 (0 ~ 29)
		// +1을 통해 1 ~ 30까지의 숫자를 랜덤으로 생성
	}

	print_array(arr, 10);
	max = Find_Max(arr, 10);
	printf("배열에서 가장 큰 수 : %d\n", max);
	even_odd(arr, 10);

	int *even_sum = 0;
	int *odd_sum = 0;

	even_odd_pointer(arr, 10, &even_sum, &odd_sum);
	//매개변수가 포인터 변수이므로 포인터 변수의 주소를 넘겨주어야한다

	printf("배열에서 홀수의 합은 %d, 짝수의 합은 %d\n", even_sum, odd_sum);
}
