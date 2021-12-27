#include <stdio.h>
#include <stdlib.h>

struct Book
{
	int no;
	char name[20];
	int rent_day;
	int return_day;
	// no (학번), name(도서명), rent_day(대여일), return_day(반납일)을 멤버로하는 Book이라는 구조체
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
		printf("프로그램을 종료합니다.");
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
	//구조체 Book 10개를 가지는 구조체 배열 Books

	printf("0 : 등록된 모든 도서 출력 1: 학번으로 도서 검색 2 : 반납일로 도서 검색 : ");

	int select;
	scanf_s("%d", &select);
	
	if (select == 0) {
		search(&Books, 10, select, 0);
	}
	else {
		if (select == 1) {
			printf("학번을 입력하세요 : ");
		}
		else
		{
			printf("반납일을 입력하세요 : ");
		}
		int value;
		scanf_s("%d", &value);
		search(&Books, 10, select, value);
	}
	
}
