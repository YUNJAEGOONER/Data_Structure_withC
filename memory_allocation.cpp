#include <iostream>
using namespace std;

void print_memory(int size,int *memory){

	for (int i = 0; i < size ; i++) {
		cout << "주소 값 : " << memory+i << " 저장 되어 있는 값 : " << *(memory + i) << endl;
	}

}

int main() {
	int size = 10;
	int* memory = (int*)malloc(sizeof(int) * size);

	if (memory == NULL) {
		cout << "동적 메모리 할당 실패" << endl;
	}
	else
	{
		cout << "동적 메모리 할당 성공" << endl;
	}

	//malloc : 요구하는 크기의 메모리를 할당하고, 그 시작 주소를 반환한다.
	//memory는 포인터 변수임으로 cout << memory 를 할 경우 주소값이
	//*(memory)할 경우 그 주소에 저장되어 있는 값이 나오게된다
 
	for (int i = 0; i < size / 2; i++) {
		memory[i] = i;//배열처럼 index로도 접근이 가능하다.
		cout << "주소 값 : " << memory+i << " 저장 되어 있는 값 : " << memory[i] << endl;
	}

	for (int i = size/2; i < size; i++){
		*(memory + i) = i;
		//해당 주소의 값에 i를 저장
		cout << "주소 값 : " << memory+i << " 저장 되어 있는 값 : " << *(memory+i) << endl;
	}

	memory = (int*)realloc(memory,sizeof(int)*size*2);
	//realloc 함수를 이용해 메모리를 추가 할당

	for (int i = size; i < size * 2; i++) {
		*(memory + i) = i;
		cout << "주소 값 : " << memory + i << " 저장 되어 있는 값 : " << *(memory + i) << endl;
	}

	memory = (int*)realloc(memory, sizeof(int) * (size / 2));
	// realloc 함수를 이용해 메모리의 크기를 축소

	print_memory(size / 2, memory);

	free(memory);
	//메모리 할당 해제

	return 0;

}