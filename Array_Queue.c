#include<stdio.h>
#include<stdlib.h>
#define queue_size 5

typedef int element;
element queue[queue_size];
//element(int)�� 5�� ���� �ִ� �迭�� ����
 
int front = -1;
int rear = -1;

void enqueue(int data) {

	if (isFull() == 0) {
		//���ο� ��Ұ� �� �ڸ��� �ֳ� Ȯ��
		if (front == -1) {
			front = front + 1;
			rear = rear + 1;
			queue[rear] = data;
		}
		else
		{
			queue[rear+1] = data;
			rear = rear + 1;
		}	
		printf("%d Queue�� Enqueue�Ϸ�\n", data);
	}
	else {
		printf("Queue�� ��ȭ�Ǿ�����\n");
	}
}

void dequeue() {

	if (isEmpty() == 0) {
		//pop���� ��Ұ� �ִ��� Ȯ��
		if (front > queue_size -1) {
			printf("Queue �������\n");
		}
		else {

			printf("���� ���� ���� %d Dequeued\n", queue[front]);
			queue[front] = NULL;
			front = front + 1;
		}
	}
	else {
		printf("Queue�� �������\n");
	}
}

int isEmpty() {
	if (front == -1) {
		//Queue�� ��������� =>dequeue�� �� �� ����
		return 1;
	}
	return 0;
}

int isFull() {
	if (rear == queue_size - 1) {
		//=>queue�� ����ִ� ������ ���� �� =>Inqueue�� �� �� ����
		return 1;
	}
	else {
		return 0;
	}
}

void main() {

	dequeue();

	for (int i = 0; i < queue_size; i++) {
		enqueue(i + 1);
	}

	enqueue(6);

	for (int i = 0; i < queue_size; i++) {
		dequeue();
	}

	dequeue();
}