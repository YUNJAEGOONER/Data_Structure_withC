#include <stdio.h>

#define Max_Q_size 5
//Queue�� ����� 8�� ����
typedef int element;
//�ڷ��� int�� ��Ī�� element�� ����
//int�� element��� ������

element queue[Max_Q_size];
element front = -1;
element rear = -1;

int isEmpty() {
	if (front == rear){
		if (front != -1) {
			if (queue[front%Max_Q_size] == NULL) {
				printf("Empty queue\n");
			}
			else
			{
				queue[front%Max_Q_size] = NULL;
			}		
		}
		else
		{
			//front�� -1�ΰ��
			//�ƹ��͵� ���� ť
			printf("Empty Queue");
		}
	return 1;
	}
	else {
		return 0;
	}
}

int isFull() {
	if ((rear - front)%Max_Q_size == Max_Q_size - 1){
		printf("Full Queue");
	}
	else {
		return 0;
	}
}

Enqueue(data) {

	if (isFull() == 0) {
		//Queue�� Full�� �ƴҰ��

		if (rear < Max_Q_size-1) {
			if (rear == -1) {
				front = front + 1;
			}
			rear = rear + 1;
			queue[rear] = data;
		}
		else {
			if (front % Max_Q_size == Max_Q_size - 1) {
				front = front + 1;
			}
			rear = rear + 1;
			queue[rear % Max_Q_size] = data;
		}
	}

	}

Dequeue() {

	if (isEmpty() == 0) {
		if (front < Max_Q_size) {
			queue[front] = NULL;
			front = front + 1;
		}
		else {
			queue[front % Max_Q_size] = NULL;
			front = front + 1;
		}
	}
	else {

	}
	//Queue�� Empty�� �ƴ϶��
	
	//queue[front] = NULL;
	//front = front + 1;
}

void main() {

	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	//Enqueue(6);

	Dequeue();
	printf("%d %d\n", front, rear);
	Dequeue();
	printf("%d %d\n", front, rear);
	Dequeue();
	printf("%d %d\n", front, rear);
	Dequeue();
	printf("%d %d\n", front, rear);
	Dequeue();
	printf("%d %d\n", front, rear);
	

	Dequeue();
	Dequeue();
	
	//printf("%d %d %d", queue[4],rear,front);

	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	Enqueue(6);

	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();

	Dequeue();
	Dequeue();
	Dequeue();

}