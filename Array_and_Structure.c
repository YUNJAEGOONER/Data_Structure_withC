#include <stdio.h>
#include <stdlib.h>

struct Book
{
	int no;
	char name[20];
	int rent_day;
	int return_day;
	// no (�й�), name(������), rent_day(�뿩��), return_day(�ݳ���)�� ������ϴ� Book�̶�� ����ü
};

void search(struct Book* Books, int n, int select, int value) {

	switch (select)
	{

	case 0: {
		for (int i = 0; i < n; i++) {
			printf("%d %s %d %d\n", Books[i].no, Books[i].name, Books[i].rent_day, Books[i].return_day);

		}
		break;
	}

	case 1: {
		for (int i = 0; i < n; i++) {
			if (Books[i].no == value) {
				printf("%d %s %d %d\n", Books[i].no, Books[i].name, Books[i].rent_day, Books[i].return_day);
			}
		}
		break;
	}

	case 2: {
		for (int i = 0; i < n; i++) {
			if (Books[i].return_day == value) {
				printf("%d %s %d %d\n", Books[i].no, Books[i].name, Books[i].rent_day, Books[i].return_day);
			}
		}
		break;
	}

	default:
		printf("���α׷��� �����մϴ�.");
		break;
	}
}


void main() {
	struct Book Books[10] = {
		{2018111,"Python",170610,170617},
		{2018222,"JAVA",170610,170617},
		{2018333,"C ++",170611,170618},
		{2018444,"C",170610,170617},
		{2018555,"JAVA",170612,170619},
		{2018666,"Python",170610,170617},
		{2018777,"JAVA",170612,170619},
		{2018888,"Python",170612,170619},
		{2018999,"C++",170611,170618},
		{2019000,"Python",170610,170617}
	};
	//����ü Book 10���� ������ ����ü �迭 Books

	printf("0 : ��ϵ� ��� ���� ��� 1: �й����� ���� �˻� 2 : �ݳ��Ϸ� ���� �˻� : ");

	int select;
	scanf_s("%d", &select);
	
	if (select == 0) {
		search(&Books, 10, select, 0);
	}
	else {
		if (select == 1) {
			printf("�й��� �Է��ϼ��� : ");
		}
		else
		{
			printf("�ݳ����� �Է��ϼ��� : ");
		}
		int value;
		scanf_s("%d", &value);
		search(&Books, 10, select, value);
	}
	
}
