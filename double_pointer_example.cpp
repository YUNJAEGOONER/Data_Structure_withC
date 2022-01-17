#include <iostream>
using namespace std;

const char* newgreat = "Hello";

void change_greet(const char *q) {

	//포인터 변수 q에 매개변수로 받은 greet이 가진 값이 복사된다.
	// => q는 greet이 가르키는 Good Bye를 가르키고 있다.
	cout << "q = " << q <<"\n";
	q = newgreat;
	//q는 newgreat이 가르키는 Hello를 가르킴
	//greet은 여전히 Good Bye를 가르키고 있음
	cout << "q = " << q << "\n";
	//종료와 동시에 포인터 변수 q는 메모리에서 소거
}

void change_greet_pp(const char **pp){
	//포인터의 주소를 받아 왔으므로 포인터의 주소를 저장 할 수 있는 더블포인터로 받아야함
	
	cout << "pp = " << *pp << "\n";
	//이중 포인터 pp는 greet의 주소를 가지고 있다.
	//*pp를 하게되면 greet이 가르키고 있는 Good Bye이가 출력된다.
	*pp = newgreat;
	//*pp의 값을 newgreat으로 바꾸게 되면 greet이 가르키던 Good Bye도 new greet으로 바뀌게 된다.
	cout << "pp = " << *pp << "\n";
	//종료와 동시에 이중 포인터 변수 pp가 소멸되어도 greet은 Hello를 가르키고 있다.
}

int main() {
	cout<< "Double Pointer example"<<"\n";

	const char* string = "Arsenal";
	//문자열 포인터 string은 Arsenal을 가르키고있음
	cout << string << " => ";
	//*string이라고 하지않아도 string의 값이 출력됨 (배열? 이라 그런거같다)
	//정수형의 경우 => *p 를 해야 p가 가르키고있는 값이 출력 (p는 주소값을 가져옴)
	string = "Coyg";
	cout << string << "\n";
	//문자열 포인터가 가르키고 있는 값 변경
	cout << *(string + 0) << " + " << *(string + 1) << " + " << *(string + 2) << " + " << *(string + 3) << " = " << string<<"\n";


	cout << "단일 포인터" << endl;
	const char* greet = "Good Bye";
	cout << "greet = " << greet << "\n";
	//greet은 Good Bye를 가르키고 있음
	change_greet(greet);
	//char를 가르킬수 있는 포인터 변수 greet을 매개변수로 넘겨줌
	cout << "greet = " << greet << "\n";
	//greet은 Good Bye를 가르키고있음
	

	cout << "이중 포인터" << endl;
	const char* greet_pp = "Good Bye";
	cout << "greet = " << greet_pp << "\n";
	//greet_pp는 Good Bye를 가르키고 있음
	change_greet_pp(&greet_pp);
	//포인터의 주소를 매개변수로 넘김 -> 포인터의 주소를 저장 : 이중포인터
	cout << "greet = " << greet_pp << "\n";
	//greet는 Hello를 가르키고있음
	
	return 0;
}