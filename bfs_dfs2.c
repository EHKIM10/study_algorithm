#include <stdio.h>
#include <malloc.h>
typedef struct node node;
struct node
{
	int data;
	node *prev;
	node *next;
};
typedef struct queue queue;
struct queue
{
	int size;
	node * head; //input
	node * tail; //delete
};
int edge[1001][1001] = { 0 };
int N,cnt=0;
node *stack = NULL;
queue * Q = NULL;
void dfs(int *vertex,int *visited);
void bfs(int *vertex, int *visited);
void enqueue(int vertax);
int  dequeue();
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
	free(Q);
	free(stack);
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
	int i;
	int val = *vertex;
	node *temp=NULL;
	if (*(visited + val - 1) != 2)
	{
		*(visited + val - 1) = 2;
		cnt++;
		printf("%d ", val);
		enqueue(val);
		while (Q->size >= 1)
		{
			if (cnt == N)
				break;
			val = dequeue();
			for (i = 1; i <= N; i++)
			{
				if (edge[val][i] == 1 && *(visited + i - 1) != 2)
				{
					enqueue(i);
					cnt++;
					*(visited + i - 1) = 2;
					printf("%d ", i);
				}
				else
					if (cnt == N)
						break;
				
			}	
			
		}
		//if some elements are still in queue, delete all
		while (Q->size >= 1)
		{
			dequeue();
		}
	}
}
void enqueue(int vertax)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = vertax;
	temp->next = temp->prev = NULL;
	if (Q == NULL)
	{
		Q = (queue*)malloc(sizeof(queue));
		Q->size = 0;
		Q->head = Q->tail = temp;
		Q->size++;
	}
	else if (Q != NULL&&Q->size == 0)
	{
		Q->size++;
		Q->head = Q->tail = temp;
	}
	else
	{
		Q->size++;
		temp->next = Q->head;
		Q->head->prev = temp;
		Q->head = temp;
	}
}
int dequeue()
{
	int v;
	node *temp;
	if (Q == NULL)
	{
		return -1;
	}
	if (Q->tail == NULL)
	{
		return -1;
	}

	Q->size--;
	v = Q->tail->data;
	temp = Q->tail->prev;
	free(Q->tail);
	if (temp != NULL)
	{
		temp->next = NULL;
		Q->tail = temp;
	}
	else
	{
		Q->tail = NULL;
		Q->head = NULL;
		Q->size = 0;
	}
	return v;
}
