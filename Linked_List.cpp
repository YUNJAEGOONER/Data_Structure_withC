#include <iostream>

typedef struct node {
	int data;
	struct node* next;
}Node;

//이 코드에서 삽입은 항상 맨 앞에 삽입하는 경우만을 고려

void Insert_node(Node **head, int data) {
	//이중포인터를사용해 head가 가르키는 값을 변경 할 수 있다.
	//단일 포인터 사용시 매개변수로 받아 온 변수가 가르키는 값만을 변경
	//->함수종료시 해당 변수는 소멸되고, head는 여전히 원래의 것을 가르킴

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	//새로운 노드 생성을 위해 동적할당, 새로운노드의 데이터 삽입

	//Empty_Linked_List : head가 해당요소를 가르한다.
	if (*head == NULL) {
		*head = new_node;
		new_node->next = NULL;
		//*head = 새로운 노드 -> head가 새로운 노드를 가르키게한다.
		//새로운 요소의 next는 Null을 가르키도록
	}
	//이미 요소들이 삽입되어 있는 경우
	else {
		new_node->next = *head;
		*head = new_node;
	}
}

void delete_node(Node** head, int data) {
	//Linked List에 해당요소가 있는지 찾은 후 있다면 삭제
	// 
	//삭제하려는 노드를 head가 가르키고 있을 때 (첫번째 요소일 경우)
	if ((*head)->data == data) {
		*head = (*head)->next;
		//head가 삭제하려는 노드의 next가 가르키고 있던 것을 가르키게 한다.
	}
	else {
		Node* ptr = *head;
		Node* before = NULL;

		while (ptr!=NULL)
		//리스트의 마지막까지 살펴본다.
		{
			if (ptr->data==data) {
				if (ptr->next == NULL) {
					before->next = NULL;
				}
				else {
					*before->next = *ptr->next;
				}
				break;
			}
			before = ptr;
			ptr = ptr->next;
		}
		if (ptr == NULL) {
			printf("%d : 리스트에 없음\n",data);
		}
	}
}

void Display(Node* head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}

	//printf("%d ", head->next->data);
	//printf("%d ", head->next->next->data);	
}

int main() {
	Node* head = NULL;
	//Node의 주소를 저장할 수 있는 포인터 head
	//초기에는 아무것도 가르키고 있지않다

	

	//Insert_node(&head, data);
	//포인터 변수의 주소값을 매개변수로 보냄 => 이중포인터로 받는다.
	
	//delete_node(&head, data);
	//포인터 변수의 주소값을 매개변수로 보냄 => 이중포인터로 받는다.

	int insert = 10;
	int del = 10;
	int i = 0;

	//반복문을 이용하여 Linked List에 요소들을 삽입
	while (i < 10) {

		Insert_node(&head, insert + i);
		i = i + 1;
	}
	Display(head);

	printf("\nLinked List에서 10을 삭제\n");
	delete_node(&head, 10);
	Display(head);

	printf("\nLinked List에서 17을 삭제\n");
	delete_node(&head, 17);
	Display(head);

	printf("\nLinked List에서 11을 삭제\n");
	delete_node(&head, 11);
	Display(head);

	//delete_node(&head, 1);
	printf("\nLinked List에서 125를 삭제\n");
	delete_node(&head, 125);
	Display(head);

	free(head);


	return 0;
}