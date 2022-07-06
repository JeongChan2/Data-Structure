#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
	char s[15];
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}
//우선순위 히프
void priority_heap() {
	char check;		//삽입,삭제,종료를 입력받을 문자형 변수
	element item;	//히프에 들어가기전 보관함
	HeapType* h;

	h = create();
	init(h);

	while(1) {
		printf("삽입(i), 삭제(d) 종료(q): ");
		scanf_s(" %c", &check);

		if (check == 'q')
			break;
		else if (check == 'i') {
			scanf_s("%c", &check);
			printf("할일: ");
			gets_s(item.s, 15);
			printf("우선순위: ");
			scanf_s("%d", &item.key);
			insert_max_heap(h, item);
		}
		else if (check=='d') {
			if (h->heap_size == 0) {
				printf("비어있음\n");
				continue;
			}
			item = delete_max_heap(h);
			printf("제일 우선 순위가 높은 일은 %s\n", item.s);
		}
		fflush(stdin); //표준입력(키보드) 버퍼를 비워버리는 함수
	}
}

#define SIZE 8
int main(void)
{
	priority_heap();

	system("pause");

	return 0;
}
