#include<stdio.h>
#include<stdlib.h>
#define queue_size 5

typedef int element;
element queue[queue_size];
//element(int)가 5개 들어갈수 있는 배열을 생성
 
int front = -1;
int rear = -1;

void enqueue(int data) {

	if (isFull() == 0) {
		//새로운 요소가 들어갈 자리가 있나 확인
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
		printf("%d Queue에 Enqueue완료\n", data);
	}
	else {
		printf("Queue가 포화되어있음\n");
	}
}

void dequeue() {

	if (isEmpty() == 0) {
		//pop을할 요소가 있는지 확인
		if (front > queue_size -1) {
			printf("Queue 비어있음\n");
		}
		else {

			printf("가장 먼저 들어온 %d Dequeued\n", queue[front]);
			queue[front] = NULL;
			front = front + 1;
		}
	}
	else {
		printf("Queue가 비어있음\n");
	}
}

int isEmpty() {
	if (front == -1) {
		//Queue이 비어있을때 =>dequeue을 할 수 없음
		return 1;
	}
	return 0;
}

int isFull() {
	if (rear == queue_size - 1) {
		//=>queue에 비어있는 공간이 없을 때 =>Inqueue를 할 수 없음
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