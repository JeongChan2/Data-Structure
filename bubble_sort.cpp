#include<stdio.h>

#define element int
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )

void insert_sort(element list[], int n) {
	int i, j;
	element temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
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