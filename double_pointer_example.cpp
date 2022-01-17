#include <iostream>
using namespace std;

const char* newgreat = "Hello";

void change_greet(const char *q) {

	//������ ���� q�� �Ű������� ���� greet�� ���� ���� ����ȴ�.
	// => q�� greet�� ����Ű�� Good Bye�� ����Ű�� �ִ�.
	cout << "q = " << q <<"\n";
	q = newgreat;
	//q�� newgreat�� ����Ű�� Hello�� ����Ŵ
	//greet�� ������ Good Bye�� ����Ű�� ����
	cout << "q = " << q << "\n";
	//����� ���ÿ� ������ ���� q�� �޸𸮿��� �Ұ�
}

void change_greet_pp(const char **pp){
	//�������� �ּҸ� �޾� �����Ƿ� �������� �ּҸ� ���� �� �� �ִ� ���������ͷ� �޾ƾ���
	
	cout << "pp = " << *pp << "\n";
	//���� ������ pp�� greet�� �ּҸ� ������ �ִ�.
	//*pp�� �ϰԵǸ� greet�� ����Ű�� �ִ� Good Bye�̰� ��µȴ�.
	*pp = newgreat;
	//*pp�� ���� newgreat���� �ٲٰ� �Ǹ� greet�� ����Ű�� Good Bye�� new greet���� �ٲ�� �ȴ�.
	cout << "pp = " << *pp << "\n";
	//����� ���ÿ� ���� ������ ���� pp�� �Ҹ�Ǿ greet�� Hello�� ����Ű�� �ִ�.
}

int main() {
	cout<< "Double Pointer example"<<"\n";

	const char* string = "Arsenal";
	//���ڿ� ������ string�� Arsenal�� ����Ű������
	cout << string << " => ";
	//*string�̶�� �����ʾƵ� string�� ���� ��µ� (�迭? �̶� �׷��Ű���)
	//�������� ��� => *p �� �ؾ� p�� ����Ű���ִ� ���� ��� (p�� �ּҰ��� ������)
	string = "Coyg";
	cout << string << "\n";
	//���ڿ� �����Ͱ� ����Ű�� �ִ� �� ����
	cout << *(string + 0) << " + " << *(string + 1) << " + " << *(string + 2) << " + " << *(string + 3) << " = " << string<<"\n";


	cout << "���� ������" << endl;
	const char* greet = "Good Bye";
	cout << "greet = " << greet << "\n";
	//greet�� Good Bye�� ����Ű�� ����
	change_greet(greet);
	//char�� ����ų�� �ִ� ������ ���� greet�� �Ű������� �Ѱ���
	cout << "greet = " << greet << "\n";
	//greet�� Good Bye�� ����Ű������
	

	cout << "���� ������" << endl;
	const char* greet_pp = "Good Bye";
	cout << "greet = " << greet_pp << "\n";
	//greet_pp�� Good Bye�� ����Ű�� ����
	change_greet_pp(&greet_pp);
	//�������� �ּҸ� �Ű������� �ѱ� -> �������� �ּҸ� ���� : ����������
	cout << "greet = " << greet_pp << "\n";
	//greet�� Hello�� ����Ű������
	
	return 0;
}