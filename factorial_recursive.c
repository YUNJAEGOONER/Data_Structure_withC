#include <stdio.h>

int factorial(int n) { 
	
	if (n == 0) {
		return 1;
		//결과를 아는 0!이 될때까지 
		//0 ! = 1
	}
	else
	{
		return n * factorial(n - 1);
	}
}

void main() {
	printf("Factorial calculator\nInsert n :");

	int n;
	scanf_s("%d", &n);
	int result = factorial(n);

	printf("%d! = %d", n, result);
}
