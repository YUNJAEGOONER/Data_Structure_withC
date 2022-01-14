#include <iostream>
using namespace std;

//배열의 매개변수 전달 방법 -> 일반적인 매개변수 전달 방법 
int sum_of_array(int array[], int size) {

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + array[i];
	}
	return sum;
}

//a(배열)는 포인터 변수임으로 포인터를 매개변수로 받을 수 있다.
float average_of_array_pointer(int * array, int size) {
	
	float sum = 0;
	float avg;
	for (int i = 0; i < size; i++) {
		sum = sum + array[i];
	}
	avg = sum / size;
	return avg;
}

int main(){

	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//정수형 자료 10개를 담을 수 있는 배열 a
	//배열의 이름(a)은 배열의 시작주소를 저장하는 포인터 변수이다.

	//a는 포인터 변수임으로 cout << a를 하게 되면 주소가, cout << *a를 하게되면 그 주소에 저장되어 있는 값이 나온다.
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		cout << "주소가 " << a + i << "인 곳에는 " << *(a + i) << "이 저장되어 있다." << endl;
	}
	//int가 4byte이기 때문에 주소가 4씩 차이가 난다.

	//배열은 index로도 접근이 가능하다.
	
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	int sum;;
	float avg;
	sum = sum_of_array(a, sizeof(a) / sizeof(int));
	cout << "배열의 합은 :" << sum << endl;
	avg = average_of_array_pointer(a, sizeof(a) / sizeof(int));
	cout << "배열의 평균은 :" << avg << endl;
	return 0;
}