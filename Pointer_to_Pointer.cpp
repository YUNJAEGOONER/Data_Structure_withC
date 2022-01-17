#include <iostream>
using namespace std;

int main() {
	cout << "Double Pointer" << endl;
	
	int x = 10;
	
	int* p = &x; 
	// & : 변수로부터 그 변수의 주소를 추출
	//포인터 변수p는 x의 주소를 저장
	
	int** pp = &p;
	//포인터 : 변수의 주소를 저장
	//더블포인터 : 포인터 변수의 주소를 저장 
	//포인터 변수인 p의 주소를 추출해 저장

	cout << "x =" << x <<endl;
	cout << "p의 주소: " << p << " p는 " << *p <<"을 가르키고있음"<<endl;
	//* : 포인터변수가 가르키는 값을 가져옴
	cout << "*p의 주소: " << pp << " pp는 " << *pp << "을 가르키고있음 (p의 주소)"<<endl;
	//더블 포인터임으로 *pp는 **pp가 가르키고있는 p의 주소가 나오게된다.
	//더블 포인터인 pp가 가르키는 값을 얻기 위해서는 **pp를 해야한다.
	cout << "*p의 주소: " << pp << " pp는 " << **pp << "을 가르키고있음"<<endl;

	*p = 20;
	//포인터가 가르키는 값을 변경을 통해 x, p, pp의 값을 모두 변경 가능
	cout << x << "\n";
	cout << *p << "\n";
	//* : 포인터변수가 가르키는 값을 가져옴
	cout << **pp << "\n";

	**pp = 50;
	//더블 포인터가 가르키는 값을 변경을 통해 x, p, pp의 값을 모두 변경 가능
	cout << x << "\n";
	cout << *p << "\n";
	cout << **pp << "\n";

	return 0;
}