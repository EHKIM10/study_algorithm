#include <stdio.h>
#include <malloc.h>
typedef struct node node;
struct node
{
	int data;
	node *prev;
	node *next;
};
int edge[1001][1001] = { 0 };
int N,cnt=0;
node *stack = NULL;
void dfs(int *vertex,int *visited);
void bfs(int *vertex, int *visited);
int main()
{
	int M, V,ver1,ver2,i;
	int *vertex, *visited;

	scanf("%d%d%d", &N,&M,&V);
	vertex = (int*)malloc(sizeof(int)*N);
	visited = (int*)malloc(sizeof(int)*N);
	for (i = 0; i < N; i++)
	{
		vertex[i] = i + 1;
		visited[i] = 0;
	}

	for (i = 0; i < M; i++)
	{
		scanf("%d%d", &ver1, &ver2);
		edge[ver1][ver2] = 1;
		edge[ver2][ver1] = 1;
	}

	dfs(vertex+V-1, visited);
	printf("\n");
	cnt = 0;
	bfs(vertex + V - 1, visited);

	free(vertex);
	free(visited);
	return 0;
}
void dfs(int *vertex, int *visited)
{
	int i;
	node *temp;

	if (*(visited + (*vertex) - 1) == 0)
	{
		if (stack == NULL)
		{
			stack = (node*)malloc(sizeof(node));
			stack->prev = NULL;
			stack->data = *vertex;
		}
		else
		{
			temp = (node*)malloc(sizeof(node));
			temp->data = *vertex;
			temp->prev = stack;
			stack = temp;
		}
		*(visited + (*vertex) - 1) = 1;
		cnt++;
		printf("%d ", *vertex);
		for (i = 1; i <= N; i++)
		{
			if (edge[*vertex][i] == 1&& *(visited + i- 1) == 0)
				dfs(vertex+(i - (*vertex )), visited);
			if (cnt == N)
				break;
		}
		temp = stack->prev;
		free(stack);
		if (temp != NULL)
			stack = temp;
		else
		{
			stack = NULL;
			return;
		}

	}
}
void bfs(int *vertex, int *visited)
{
	int i,size=0;
	node *temp,*queue=NULL;
	queue = (node*)malloc(sizeof(node));
	if (*(visited + (*vertex) - 1) != 2)
	{
		*(visited + (*vertex) - 1) = 2;
		size++;
		cnt++;
		printf("%d ", *vertex);
		queue->data = *vertex;
		queue->next = NULL;
		while (size != 0)
		{
			if (*(visited + (*vertex) - 1) != 2)
			{
			}
		}
	}
}
