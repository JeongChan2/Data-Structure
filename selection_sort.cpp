#include<stdio.h>

#define element int
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(element list[], int n) {
	int i, k;
	element least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (k = i + 1; k < n; k++)
			if (list[k] < list[least])
				least = k;
		SWAP(list[i], list[least], temp);
	}
}

int main()
{
	element list[] = { 5,3,8,1,2,7 };
	int size = sizeof(list) / sizeof(list[0]); //배열 list의 크기
	selection_sort(list, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}

	return 0;
}