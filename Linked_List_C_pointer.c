#include <stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;
//typedef을 이용해 int라는 자료형을 element로 정의한다. 
// 쉽게 말해 타입에 별칭을 생성하는것이다 int라는 type에 element라는 별칭을 생성
//정수 a를 선언하기 위해 int a; 대신에 element a라고 선언해도 된다.

typedef struct node {
	element data;
	struct node* next;
	//다음 노드의 주소를 저장할 포인터
	//struct node 형태의 주소값을 저장하는 포인터 변수 
}Node;
//Node라는 구조체는 data (int)와 next(Pointer)를 멤버변수로 가지고 있다.

//맨 앞쪽에 새로운 노드를 추가하는 경우만 반영
//head == Null이면 head가 새로운노드를 가리키면 된다.
//head != Null이면 새로운노드가 head가 가리키고 있던 노드를 가리키고, head는 새로운 노드를 가르키면 된다.

Linked_Insert(Node** head, int data) {

	Node* new_node = (Node*)malloc(sizeof(Node));
	//새로운 노드 생성 
	new_node->data = data;
	//새로운 노드의 data자리에 매개변수로 받은 data를 삽입

	if (*head == NULL) {
		*head = new_node;
		new_node->next = NULL;
	}
	//head == Null이면 head가 새로운노드를 가리키면 된다.

	else
	{
		new_node->next = *head;
		*head = new_node;

	}
	//새로운노드가 head가 가리키고 있던 노드를 가리키고, head는 새로운 노드를 가르키면 된다.
}

//특정노드를 삭제하는 경우
//찾으려고 하는 노드의 data를 매개변수로 받아와서 해당 노드 찾기
//해당노드의 이전노드를 해당노드의 다음노드와 연결
Linked_Del(Node** head, Node* Before, int del) {

	if ((*head)->data == del) {
		//해당 노드를 찾았을때

		if ((*head) == Before) {
			//해당노드가 리스트의 첫 번째 노드 일때 
			*head = (*head)->next;
		}
		else {
			Before->next = (*head)->next;
			//해당 노드의 next노드를 해당노드의 이전노드가 가리키도록한다.
			free(head);
		}
	}
	else
	{
		Linked_Del(&((*head)->next), Before->next, del);
		//재귀함수를 이용해 다음노드를 검색
	}
}

Display(Node* head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}

	//printf("%d ", head->next->data);
	//printf("%d ", head->next->next->data);	
}

void main() {

	Node* head = NULL;
	int insert = 5;
	int del = 5;
	int i = 0;

	//반복문을 이용하여 Linked List에 요소들을 삽입
	while (i < 10) {

		Linked_Insert(&head, insert + i);
		i = i + 1;
	}
	Display(head);

	printf("\nLinked List에서 10을 삭제\n");
	Linked_Del(&head, head, 10);
	Display(head);

	free(head);
}