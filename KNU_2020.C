#include <stdio.h>
int rec(int n, int* res) {
	
	printf("res는 %d를 가르키고 있다.\n", *res);


	//주소를 받아야 함으로 매개변수를 포인터 변수로
	int result = 0;
	static int count = 0;
	//정적변수 -> 함수 실행시 초기화가 아닌 유지

	if(n < 2) {
	//종료조건 
		return result;
	}
	//종료조건이 충족되지 않을 때
	// if n이 3의 배수이면 result에 자기자신을 더하고, 재귀
	// else 재귀

	if (n % 3 == 0) {
		result = rec(n - 1, res) + n;
		count = count + 1;
	}
	else
	{
		result = rec(n - 1, res);
	}
	
	printf("res는 %d를 가르키고 있다.\n" ,* res);
	// *을 이용해 res(포인터변수)의 값을 가지고 온다.

	*res = result + count;
	//res가 가르키고 있는 값 자체를 변경

	printf("*res를 result + count로 하면서 res는 %d를 가르키고 있다.\n", *res);
	
	return result;
}

void main(){
	int result = 0;
	int sum;

	sum = rec(5, &result);
	//result의 주소를 매개변수로 넘김
	printf("1) %d, %d\n", sum, result);

	sum = rec(6, &result);
	//result의 주소를 매개변수로 넘김
	printf("2) %d, %d\n", sum, result);

}