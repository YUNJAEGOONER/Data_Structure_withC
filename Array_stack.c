#include<stdio.h>
#include<stdlib.h>
#define stack_size 5

typedef int element;
element stack[stack_size];
//element(int)�� 5�� ���� �ִ� �迭�� ����

int top = -1;
//�ʱ� top���� -1�� ���� 
//ù��° ��Ұ� ������ �� top + 1���ϸ� 0 �̹Ƿ� �迭���� ù��° ����� index�� ǥ�� 


void push(int data) {
	if (isFull () == 0) {
		//���ο� ��Ұ� �� �ڸ��� �ֳ� Ȯ��
		top = top + 1;
		stack[top] = data;
		printf("%d Stack�� Push�Ϸ�\n", data);
	}
	else {
		printf("Stack�� ��ȭ�Ǿ�����\n");
	}
}

void pop() {
	if (isEmpty() == 0) {
		//pop���� ��Ұ� �ִ��� Ȯ��
		printf("���� �������� ���� %d Pop\n", stack[top]);
		stack[top] = NULL;
		top = top - 1;
	}
	else {
		printf("Stack�� �������\n");
	}
}

int isEmpty() {
	if (top == -1) {
		//Stack�� ��������� =>Pop�� �� �� ����
		return 1;
	}
	return 0;
}

int isFull() {
	if (top == stack_size -1) {
		//=>Stack�� ����ִ� ������ ���� �� =>Push�� �� �� ����
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