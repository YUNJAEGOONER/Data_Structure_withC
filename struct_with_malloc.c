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
		printf("학번 : ");
		scanf_s("%d", &(std + i)->no);

		printf("이름 : ");
		scanf_s("%s", (std + i)->name, 20);
		//name은 char 20개로 이루어진 char 배열
		//배열의 이름은	배열 이름자체가 주소값을 의미하기 때문에 & 필요없다.
		printf("중간 : ");
		scanf_s("%d", &(std + i)->mid);

		printf("기말 : ");
		scanf_s("%d", &(std + i)->final);
		i = i + 1;
	}
}

void add_student(Student *std, int n, int add) {
	int i = n;

	while (i < add+n)
	{
		printf("학번 : ");
		scanf_s("%d", &(std + i)->no);

		printf("이름 : ");
		scanf_s("%s", (std + i)->name, 20);
		//name은 char 20개로 이루어진 char 배열
		//배열의 이름은	배열 이름자체가 주소값을 의미하기 때문에 & 필요없다.
		printf("중간 : ");
		scanf_s("%d", &(std + i)->mid);

		printf("기말 : ");
		scanf_s("%d", &(std + i)->final);
		i = i + 1;
	}
	
}

void print(Student * std, int n) {
	for (int i = 0; i < n ; i++) {
		printf("학번 :%d 이름 :%s 중간 :%d, 기말 :%d\n", (std + i)->no, (std + i)->name, (std + i)->mid, (std + i)->final);
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
	printf("추가할 학생 수 : ");
	scanf_s("%d", &add);
	int sum = n + add;

	std = (Student*)realloc(std, sizeof(Student) * (sum));
	//memory realloc을 이용해 메모리 크기 변경
	add_student(std, n ,add);

	//추가된 학생들도 정렬하고, print
	sort(std, sum);
	print(std, sum);
}