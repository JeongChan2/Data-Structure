#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define MAX_QUEUE_SIZE 20

#define TRUE 1
#define FALSE 0

typedef int element;

//깊이,너비 DFS BFS 공유
int visited[MAX_VERTICES] = { 0 };

typedef struct QueueType {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void init(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}

bool is_empty(QueueType* q) {
	if (q->front == q->rear) return TRUE;
	else
		return FALSE;
}

bool is_full(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1) return TRUE;
	else
		return FALSE;
}

void enqueue(QueueType* q, element e) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 포화상태입니다.");
		return;
	}
	else {
		q->data[++(q->rear)] = e;
	}
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다.");
		return -1;
	}
	else {
		return q->data[++(q->front)];
	}
}

element peek(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다.");
		return -1;
	}
	else {
		return q->data[(q->front) + 1];
	}
}

typedef struct GraphType {
	int n;	// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType* g) {
	int r, c;
	for (r = 0; r < g->n; r++) {
		for (c = 0; c < g->n; c++)
			printf("%d ", g->adj_mat[r][c]);
		printf("\n");
	}
}

void dfs_mat(GraphType* g, element v) {
	visited[v] = TRUE;
	printf("정점 %d -> ", v);
	for (int u = 0; u < g->n; u++) {
		if (!visited[u] && g->adj_mat[v][u]) {
			dfs_mat(g, u);
		}
	}
}

void bfs_mat(GraphType* g, element v) {

	int w;

	visited[v] = TRUE;
	QueueType q;
	init(&q);
	enqueue(&q, v);

	while (!is_empty(&q)) {
		v = dequeue(&q);
		printf("%d -> ", v);
		for (w = 0; w < g->n; w++) {
			if (!visited[w] && g->adj_mat[v][w]) {
				enqueue(&q, w);
				visited[w] = TRUE;
			}
		}
	}
}

int main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);
	print_adj_mat(g);

	printf("너비 우선탐색\n");
	bfs_mat(g, 0);
	printf("\n");

	free(g);
	return 0;
}
