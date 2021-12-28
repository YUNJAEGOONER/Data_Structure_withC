#include <stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Student {

	int no;
	char name[20];
	int mid;
	int final;

}Student;

void Insert_student(Student* std, int n) {

	int i = 0;
	while (i < n)
	{
		printf("�й� : ");
		scanf_s("%d", &(std + i)->no);

		printf("�̸� : ");
		scanf_s("%s", (std + i)->name, 20);
		//name�� char 20���� �̷���� char �迭
		//�迭�� �̸���	�迭 �̸���ü�� �ּҰ��� �ǹ��ϱ� ������ & �ʿ����.
		printf("�߰� : ");
		scanf_s("%d", &(std + i)->mid);

		printf("�⸻ : ");
		scanf_s("%d", &(std + i)->final);
		i = i + 1;
	}
}

void add_student(Student *std, int n, int add) {
	int i = n;

	while (i < add+n)
	{
		printf("�й� : ");
		scanf_s("%d", &(std + i)->no);

		printf("�̸� : ");
		scanf_s("%s", (std + i)->name, 20);
		//name�� char 20���� �̷���� char �迭
		//�迭�� �̸���	�迭 �̸���ü�� �ּҰ��� �ǹ��ϱ� ������ & �ʿ����.
		printf("�߰� : ");
		scanf_s("%d", &(std + i)->mid);

		printf("�⸻ : ");
		scanf_s("%d", &(std + i)->final);
		i = i + 1;
	}
	
}

void print(Student * std, int n) {
	for (int i = 0; i < n ; i++) {
		printf("�й� :%d �̸� :%s �߰� :%d, �⸻ :%d\n", (std + i)->no, (std + i)->name, (std + i)->mid, (std + i)->final);
	}
}

void sort(Student* std, int n) {
	Student temp;

	for (int i = n - 1; i >= 0; i --) {
		for (int j = 0; j < i; j++) {
			if (((std + j)->final + (std + j)->mid) < ((std + j + 1)->final + (std + j+1)->mid)) {
				temp = *(std + j);
				*(std + j) = *(std + j + 1);
				*(std + j + 1) = temp;
			}
		}
	}
}

void main() {

	int n = 3;
	Student* std;
	std = (Student*)malloc(sizeof(Student) * n);
	
	Insert_student(std, n);
	sort(std, n);
	print(std, n);


	int add;
	printf("�߰��� �л� �� : ");
	scanf_s("%d", &add);
	int sum = n + add;

	std = (Student*)realloc(std, sizeof(Student) * (sum));
	//memory realloc�� �̿��� �޸� ũ�� ����
	add_student(std, n ,add);

	//�߰��� �л��鵵 �����ϰ�, print
	sort(std, sum);
	print(std, sum);
}