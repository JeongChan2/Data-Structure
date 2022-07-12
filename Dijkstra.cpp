#include<stdio.h>
#include <climits>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void print_status(GraphType* g) {
	int i;
	static int step = 1;
	if (step == 1)
		printf("\t\t  0\t1\t2\t3\t4\t5\t6\t\n\n");
	printf("STEP %d: distance: ", step++);
	for (i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf("*\t");
		else
			printf("%d\t", distance[i]);
	}
	printf("\n        found:    ");
	for (i = 0; i < g->n; i++) {
		printf("%d\t",selected[i]);
	}
	printf("\n");
}

int choose_minpos(int n)
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !selected[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void shortest_path(GraphType* g, int v) {

	int i, min_vertex, z;

	//초기화
	for (i = 0; i < g->n; i++) {
		distance[i] = g->weight[v][i];
		selected[i] = FALSE;
	}
	selected[v] = TRUE;

	//v는 이미 방문했으므로 g->n-1 까지만 반복
	for (i = 0; i < g->n - 1; i++) {
		print_status(g);
		min_vertex = choose_minpos(g->n);
		selected[min_vertex] = TRUE;
		for (z = 0; z < g->n; z++) {
			if (!selected[z] && distance[min_vertex] + g->weight[min_vertex][z] < distance[z]) {
				distance[z] = distance[min_vertex] + g->weight[min_vertex][z];
			}
		}
	}
}

int main(void)
{
	GraphType g = { 7,
	{{ 0,  7,  INF, INF,   3,  10, INF },
	{ 7,  0,    4,  10,   2,   6, INF },
	{ INF,  4,    0,   2, INF, INF, INF },
	{ INF, 10,    2,   0,  11,   9,   4 },
	{ 3,  2,  INF,  11,   0, INF,   5 },
	{ 10,  6,  INF,   9, INF,   0, INF },
	{ INF, INF, INF,   4,   5, INF,   0 } }
	};
	shortest_path(&g, 0);
	return 0;
}
