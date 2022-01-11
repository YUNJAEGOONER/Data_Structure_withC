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

//재귀함수 : 종료조건이 충족 될때까지 반복적으로 스스로를 불러내면 주어진 작업을 수행
int factorial(int n) {
	
	if (n == 0) {
	//종료조건 
		return 1;
	}
	else {
	//종료조건이 충족되지 않았으므로 반복적으로 스스로를 불러냄
		return n * factorial(n - 1);
	}
}

int array_sum(int array [10] , int size) {

	static int sum = 0;
	//정적변수이므로 함수실행시 초기화가 아닌 그 값을 계속 가지고 있음

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
	cout << i << "번째 fibbonaci 수열은 " << result_fibbo << endl;
	fibbo_print(i);

	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int result_sum = array_sum(array, sizeof(array) / sizeof(int) -1);
	
	cout << result_sum << endl;

	return 0;
}