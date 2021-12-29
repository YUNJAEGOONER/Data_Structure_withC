#include<stdio.h>
#include<stdlib.h>
#define stack_size 5

typedef int element;
element stack[stack_size];
//element(int)가 5개 들어갈수 있는 배열을 생성

int top = -1;
//초기 top값을 -1로 지정 
//첫번째 요소가 들어왔을 때 top + 1을하면 0 이므로 배열에서 첫번째 요소의 index를 표현 


void push(int data) {
	if (isFull () == 0) {
		//새로운 요소가 들어갈 자리가 있나 확인
		top = top + 1;
		stack[top] = data;
		printf("%d Stack에 Push완료\n", data);
	}
	else {
		printf("Stack이 포화되어있음\n");
	}
}

void pop() {
	if (isEmpty() == 0) {
		//pop을할 요소가 있는지 확인
		printf("가장 마지막에 들어온 %d Pop\n", stack[top]);
		stack[top] = NULL;
		top = top - 1;
	}
	else {
		printf("Stack이 비어있음\n");
	}
}

int isEmpty() {
	if (top == -1) {
		//Stack이 비어있을때 =>Pop을 할 수 없음
		return 1;
	}
	return 0;
}

int isFull() {
	if (top == stack_size -1) {
		//=>Stack에 비어있는 공간이 없을 때 =>Push를 할 수 없음
		return 1;
	}
	else {
		return 0;
	}
}

void main() {

	pop();
	for (int i = 0; i < stack_size; i++) {
		push(i+1);
	}
	push(6);
	pop();
	push(6); 
	for (int i = 0; i < stack_size; i++) {
		pop();
	}
	pop();
	
}