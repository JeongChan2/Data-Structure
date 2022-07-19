#include<stdio.h>

#define element record
#define NAME_SIZE 10

typedef struct {
	int key;
	char name[NAME_SIZE];
} record;

void insert_sort(element list[], int n) {
	int i, j;
	element record;
	int key;
	for (i = 1; i < n; i++) {
		record = list[i];
		for (j = i - 1; j >= 0 && list[j].key > record.key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = record;
	}
}

int main()
{
	element list[] = { {6,"GOM"}, {1,"LEE"},{4,"KIM"},{2,"SON"},{3,"PARK"}};
	int size = sizeof(list) / sizeof(list[0]); //배열 list의 크기
	insert_sort(list, size);
	for (int i = 0; i < size; i++) {
		printf("%s\t", list[i].name);
	}

	return 0;
}
