#include<stdio.h>

#define element int
#define SIZE 6

void insert_sort(element list[], int n) {
	int i, j, k;
	element key;
	for (i = 0; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
		printf("( "); //-------
		for (k = 0; k <= i; k++) {
			printf("%d ", list[k]);
		}
		if (i == 0)
			printf(")\t\t\t");
		else if (i == n - 1)
			printf(")\t");
		else
			printf(")\t\t");  //���ĵȹ迭���� ���-------

		printf("( "); //-----
		for (k; k <= n-1; k++) {
			printf("%d ", list[k]);
		}
		if (i == n-2 || i == n-1)
			printf(")\t\t\t");
		else
			printf(")\t\t");; //���� ���ľȵ� �迭���� ���------

		printf("%d����\n", key);

	}
}

int main()
{
	element list[SIZE] = {};
	char tm; //,����뵵
	printf("6���� ���� �Է�\n");
	printf("()\t\t\t( ");
	scanf_s("%d %d %d %d %d %d", &list[0], &list[1], &list[2], &list[3], &list[4], &list[5]);
	insert_sort(list, SIZE);

	return 0;
}