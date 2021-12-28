#include <stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;
//typedef�� �̿��� int��� �ڷ����� element�� �����Ѵ�. 
// ���� ���� Ÿ�Կ� ��Ī�� �����ϴ°��̴� int��� type�� element��� ��Ī�� ����
//���� a�� �����ϱ� ���� int a; ��ſ� element a��� �����ص� �ȴ�.

typedef struct node {
	element data;
	struct node* next;
	//���� ����� �ּҸ� ������ ������
	//struct node ������ �ּҰ��� �����ϴ� ������ ���� 
}Node;
//Node��� ����ü�� data (int)�� next(Pointer)�� ��������� ������ �ִ�.

//�� ���ʿ� ���ο� ��带 �߰��ϴ� ��츸 �ݿ�
//head == Null�̸� head�� ���ο��带 ����Ű�� �ȴ�.
//head != Null�̸� ���ο��尡 head�� ����Ű�� �ִ� ��带 ����Ű��, head�� ���ο� ��带 ����Ű�� �ȴ�.

Linked_Insert(Node** head, int data) {

	Node* new_node = (Node*)malloc(sizeof(Node));
	//���ο� ��� ���� 
	new_node->data = data;
	//���ο� ����� data�ڸ��� �Ű������� ���� data�� ����

	if (*head == NULL) {
		*head = new_node;
		new_node->next = NULL;
	}
	//head == Null�̸� head�� ���ο��带 ����Ű�� �ȴ�.

	else
	{
		new_node->next = *head;
		*head = new_node;

	}
	//���ο��尡 head�� ����Ű�� �ִ� ��带 ����Ű��, head�� ���ο� ��带 ����Ű�� �ȴ�.
}

//Ư����带 �����ϴ� ���
//ã������ �ϴ� ����� data�� �Ű������� �޾ƿͼ� �ش� ��� ã��
//�ش����� ������带 �ش����� �������� ����
Linked_Del(Node** head, Node* Before, int del) {

	if ((*head)->data == del) {
		//�ش� ��带 ã������

		if ((*head) == Before) {
			//�ش��尡 ����Ʈ�� ù ��° ��� �϶� 
			*head = (*head)->next;
		}
		else {
			Before->next = (*head)->next;
			//�ش� ����� next��带 �ش����� ������尡 ����Ű�����Ѵ�.
			free(head);
		}
	}
	else
	{
		Linked_Del(&((*head)->next), Before->next, del);
		//����Լ��� �̿��� ������带 �˻�
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

	//�ݺ����� �̿��Ͽ� Linked List�� ��ҵ��� ����
	while (i < 10) {

		Linked_Insert(&head, insert + i);
		i = i + 1;
	}
	Display(head);

	printf("\nLinked List���� 10�� ����\n");
	Linked_Del(&head, head, 10);
	Display(head);

	free(head);
}