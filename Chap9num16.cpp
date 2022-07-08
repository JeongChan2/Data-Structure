#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
	int avail;
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

void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.avail < h->heap[i / 2].avail)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].avail) > h->heap[child + 1].avail)
			child++;
		if (temp.avail < h->heap[child].avail)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

//이진탐색
int binsearch(HeapType* h, int key) {
	int low, mid, high;
	low = 1;
	high = h->heap_size;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == h->heap[mid].avail)
			return mid;
		else if (key < h->heap[mid].avail)
			high = mid - 1;
		else if (key > h->heap[mid].avail)
			low = mid + 1;
	}
	return -1; //실패시
}

//이진탐색을 이용해 삭제
element delete_select_heap(HeapType* h, int avail) {
	int parent, child, key;
	element item, temp;

	if ((key = binsearch(h, avail)) != -1) {
		printf("%d\n", key);
		item = h->heap[key];
		temp = h->heap[(h->heap_size)--];
		parent = key;
		child = key*2;
		while (child <= h->heap_size) {
			if ((child < h->heap_size) &&
				(h->heap[child].avail) > h->heap[child + 1].avail)
				child++;
			if (temp.avail < h->heap[child].avail)
				break;
			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
		h->heap[parent] = temp;
		return item;
	}
	
}

void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_min_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_min_heap(h);
	}
	free(h);
}

int main(void)
{
	HeapType* h;
	h = create();
	init(h);

	element e1 = { 10 }, e2 = { 20 }, e3 = { 30 };
	element e4;
	insert_min_heap(h, e1);
	insert_min_heap(h, e2);
	insert_min_heap(h, e3);
	e4 = delete_select_heap(h, 30);
	printf("%d\n", e4.avail);
	for (int i = 1; i <= h->heap_size; i++) {
		printf("%d . %d\n",i, h->heap[i].avail);
	}
	system("pause");

	free(h);
	return 0;
}
