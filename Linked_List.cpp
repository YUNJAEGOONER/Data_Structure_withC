#include <iostream>

typedef struct node {
	int data;
	struct node* next;
}Node;

//�� �ڵ忡�� ������ �׻� �� �տ� �����ϴ� ��츸�� ���

void Insert_node(Node **head, int data) {
	//���������͸������ head�� ����Ű�� ���� ���� �� �� �ִ�.
	//���� ������ ���� �Ű������� �޾� �� ������ ����Ű�� ������ ����
	//->�Լ������ �ش� ������ �Ҹ�ǰ�, head�� ������ ������ ���� ����Ŵ

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	//���ο� ��� ������ ���� �����Ҵ�, ���ο����� ������ ����

	//Empty_Linked_List : head�� �ش��Ҹ� �����Ѵ�.
	if (*head == NULL) {
		*head = new_node;
		new_node->next = NULL;
		//*head = ���ο� ��� -> head�� ���ο� ��带 ����Ű���Ѵ�.
		//���ο� ����� next�� Null�� ����Ű����
	}
	//�̹� ��ҵ��� ���ԵǾ� �ִ� ���
	else {
		new_node->next = *head;
		*head = new_node;
	}
}

void delete_node(Node** head, int data) {
	//Linked List�� �ش��Ұ� �ִ��� ã�� �� �ִٸ� ����
	// 
	//�����Ϸ��� ��带 head�� ����Ű�� ���� �� (ù��° ����� ���)
	if ((*head)->data == data) {
		*head = (*head)->next;
		//head�� �����Ϸ��� ����� next�� ����Ű�� �ִ� ���� ����Ű�� �Ѵ�.
	}
	else {
		Node* ptr = *head;
		Node* before = NULL;

		while (ptr!=NULL)
		//����Ʈ�� ���������� ���캻��.
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
			printf("%d : ����Ʈ�� ����\n",data);
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
	//Node�� �ּҸ� ������ �� �ִ� ������ head
	//�ʱ⿡�� �ƹ��͵� ����Ű�� �����ʴ�

	

	//Insert_node(&head, data);
	//������ ������ �ּҰ��� �Ű������� ���� => ���������ͷ� �޴´�.
	
	//delete_node(&head, data);
	//������ ������ �ּҰ��� �Ű������� ���� => ���������ͷ� �޴´�.

	int insert = 10;
	int del = 10;
	int i = 0;

	//�ݺ����� �̿��Ͽ� Linked List�� ��ҵ��� ����
	while (i < 10) {

		Insert_node(&head, insert + i);
		i = i + 1;
	}
	Display(head);

	printf("\nLinked List���� 10�� ����\n");
	delete_node(&head, 10);
	Display(head);

	printf("\nLinked List���� 17�� ����\n");
	delete_node(&head, 17);
	Display(head);

	printf("\nLinked List���� 11�� ����\n");
	delete_node(&head, 11);
	Display(head);

	//delete_node(&head, 1);
	printf("\nLinked List���� 125�� ����\n");
	delete_node(&head, 125);
	Display(head);

	free(head);


	return 0;
}