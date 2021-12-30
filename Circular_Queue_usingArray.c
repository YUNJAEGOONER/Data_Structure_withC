#include <stdio.h>
#define Max_Q_size 5
//Queue�� ����� 8�� ����

int queue[Max_Q_size];
int front = -1;
int rear = -1;

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
			printf("Empty Queue\n");
		}
	return 1;
	}

	else {
		//Queue�� Empty�� �ƴϴ�
		//Queue�� Dequeue�Ҽ� �ִ� ��Ұ� �ִ�.
		return 0;
	}
}

int isFull() {

	if ((rear - front)%Max_Q_size == Max_Q_size - 1){
		printf("Full Queue\n");
		return 1;
	}
	else {
		//Queue�� Full�� �ƴϴ�
		//Queue�� Enqueue�� ������ �ִ�.
		return 0;
	}
}

Enqueue(data) {

	if (isFull() == 0) {
		//Queue�� Full�� �ƴ� -> enqueue����
		if (rear == -1) {
			front = front + 1;
		}
		else if (front % Max_Q_size == Max_Q_size - 1) {
			front = front + 1;
		}
		rear = rear + 1;
		queue[rear % Max_Q_size] = data;
	}
}

Dequeue() {
	if (isEmpty() == 0) {
		// Queue�� Empty�� �ƴ� -> Dequeue����
		queue[front % Max_Q_size] = NULL;
		front = front + 1;
	}
}

void main() {
	Dequeue();
	
	for (int i = 0; i < Max_Q_size; i++) {
		Enqueue(i + 1);
	}
	
	for (int i = 0; i < Max_Q_size; i++) {
		printf("%d��°�� Enqueue�� %d\n",i,queue[i]);
	}

	Enqueue(6);

	Dequeue();
	Dequeue();

	Enqueue(7);
	Enqueue(8);

	for (int i = 0; i < Max_Q_size; i++) {
		if (queue[i] != NULL) {
			printf("%d",queue[i]);
		}
	}
	printf("\n");

	for (int i = 0; i < Max_Q_size; i++) {
		Dequeue();
	}

}