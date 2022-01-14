#include <iostream>
using namespace std;

int main() {

	int a = 1;
	int b = 2;

	int* ip;
	//int형 자료의 주소값을 가질 수 있는 포인터 변수 ip
	//int형 자료를 가르킬 수 있는 포인터 변수

	ip = &a;
	//포인터 변수 ip에 a의 주소를 추출(&)하여 저장
	//ip는 변수a의 주소를 가지고 있음 
	int value = *ip;
	//ip가 가르키는 값을 알기 위한 연산자 *

	cout << "변수 a의 주소는 : " << ip << " 주소에 저장되어 있는 값 : " << value << endl;

	b = *ip; 
	//b에 ip가 가르키고있는 값, 주소 ip에 저장된 값을 저장
	cout << b << endl;
	//ip가 가르키고 있던 값인 1이 b에 저장됨

	*ip = 0;
	cout << "a :" << a << " b : "<< b << endl;
	//ip주소에 있는 값을 0으로 바꿈

	return 0;
}