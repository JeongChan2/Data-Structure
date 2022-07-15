#include<stdio.h>

#define element int

void insert_sort(element list[], int n) {
	int i, j;
	element key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}

int main()
{
	element list[] = { 5,3,8,1,2,7 };
	int size = sizeof(list) / sizeof(list[0]); //배열 list의 크기
	insert_sort(list, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}

	return 0;
}