#include <stdio.h>
#include <malloc.h>
typedef struct List list;
typedef struct Node node;
typedef struct Queue queue;
struct List
{
	node* data;
	list* next;
	list* prev;
};
struct Queue
{
	list *front;
	list *rear;
	int sz;
};
struct Node
{
	int vertax;
	int visited;
	list *adj_list;
};
node* make_graph(int N);
void del_graph(int N,node *graph);
void addEdge(int v1, int v2, node *graph);
void dfs(node *graph, int N);
void bfs(node *graph, int N);
queue* enqueue(queue *Q, node *input);
node* dequeue(queue *Q);
int cnt = 0;
int main()
{
	int N, M, V,i,h,k;
	node * graph=NULL;
	scanf("%d%d%d", &N, &M, &V);
	graph = make_graph(N);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &h, &k);
		addEdge(h, k,graph);
	}
	dfs(&graph[V-1],N);
	printf("\n");
	cnt = 0;
	bfs(&graph[V - 1],N);
	printf("\n");
	del_graph(V,graph);
	return 0;
}
queue* enqueue(queue *Q, node *input)
{
	if (Q == NULL)
	{
		Q = (queue*)malloc(sizeof(queue));
		Q->front = Q->rear = NULL;
		Q->sz = 1;
		list *Q_list = (list*)malloc(sizeof(list));
		Q_list->data = input;
		Q_list->next = NULL;
		Q_list->prev = NULL;
		Q->front = Q->rear = Q_list;
		return Q;
	}
	if (Q->front == NULL)
	{
		list *Q_list = (list*)malloc(sizeof(list));
		Q_list->data = input;
		Q_list->next = NULL;
		Q_list->prev = NULL;
		Q->front = Q->rear = Q_list;
		Q->sz = 1;
	}
	else
	{
		list *Q_list = (list*)malloc(sizeof(list));
		Q_list->data = input;
		Q_list->next = Q->front;
		Q_list->prev = NULL;
		Q->front->prev = Q_list;
		Q->front = Q_list;
		Q->sz++;
	}
	return Q;
}
node* dequeue(queue *Q)
{
	node *v;
	if (Q->sz == 0)
		return NULL;
	if (Q->sz == 1)
	{
		v = Q->front->data;
		free(Q->front);
		Q->front = Q->rear = NULL;
		Q->sz--;
	}
	else
	{
		list *temp = Q->front;
		v = Q->front->data;
		Q->front = Q->front->next;
		free(temp);
		Q->sz--;
	}
	return v;

}
void bfs(node *graph, int N)
{
	queue *Q = NULL;
	Q = enqueue(Q, graph);
	graph->visited = 2;
	cnt++;
	printf("%d ", graph->vertax);
	while (Q->sz != 0)
	{
		list *cur= dequeue(Q)->adj_list;
		while (cur != NULL)
		{
			if (cur->data->visited != 2)
			{
				Q = enqueue(Q, cur->data);
				cur->data->visited = 2;
				cnt++;
				printf("%d ", cur->data->vertax);
				
			}
			cur = cur->next;
		}
		if (cnt == N)
			break;
	}
}
void dfs(node *graph,int N)
{
	if (graph->visited == 0)
	{
		graph->visited = 1;
		printf("%d ", graph->vertax);
		cnt++;
		if (cnt == N)
			return;
		if (graph->adj_list != NULL)
		{
			list *cur = graph->adj_list;
			dfs(cur->data,N);
			if (cnt == N)
				return;
			cur = cur->next;
			while (cur != NULL)
			{
				dfs(cur->data,N);
				if (cnt == N)
					return;
				cur = cur->next;
			}
		}
	}
}
node* make_graph(int N)
{
	node * graph = (node*)malloc(sizeof(node)*N);
	int i;
	for (i = 1; i <= N; i++)
	{
		graph[i - 1].vertax = i;
		graph[i - 1].visited = 0;
		graph[i - 1].adj_list = NULL;
	}
	return graph;
}
void del_graph(int N, node *graph)
{
	int i;
	for (i = 0; i < N; i++)
	{
		list *cur = graph[i].adj_list;
		while (cur != NULL)
		{
			list *temp = cur->next;
			if (temp != NULL)
				temp->prev = NULL;
			free(cur);
			cur = temp;
		}
		graph[i].adj_list = NULL;
	}
	free(graph);
}
void addEdge(int v1, int v2, node *graph)
{
	if (graph[v1 - 1].adj_list == NULL)
	{
		graph[v1 - 1].adj_list = (list*)malloc(sizeof(list));
		graph[v1 - 1].adj_list->data = &graph[v2 - 1];
		graph[v1 - 1].adj_list->prev = NULL;
		graph[v1 - 1].adj_list->next = NULL;
	}
	else
	{
		list *cur = graph[v1 - 1].adj_list;
		while (cur != NULL)
		{
			if (graph[v2 - 1].vertax == cur->data->vertax)
				break;
			if (graph[v2 - 1].vertax < cur->data->vertax)
			{
				list *temp = (list*)malloc(sizeof(list));
				temp->data = &graph[v2 - 1];
				if (cur->prev == NULL)
				{
					temp->next = cur;
					temp->prev = NULL;
					cur->prev = temp;
					graph[v1 - 1].adj_list = temp;
				}
				else
				{
					temp->next = cur;
					temp->prev = cur->prev;
					cur->prev->next = temp;
					cur->prev = temp;
				}
				break;
			}
			if (graph[v2 - 1].vertax > cur->data->vertax)
			{
				if (cur->next == NULL)
				{
					list *temp = (list*)malloc(sizeof(list));
					temp->data = &graph[v2 - 1];
					cur->next = temp;
					temp->prev = cur;
					temp->next = NULL;
					break;
				}
				else
				{
					if (graph[v2 - 1].vertax < cur->next->data->vertax)
					{
						list *temp = (list*)malloc(sizeof(list));
						temp->data = &graph[v2 - 1];
						temp->prev = cur;
						temp->next = cur->next;
						cur->next->prev = temp;
						cur->next = temp;
						break;
					}
				}
				
			}
			cur = cur->next;
		}
	}

	if (graph[v2 - 1].adj_list == NULL)
	{
		graph[v2 - 1].adj_list = (list*)malloc(sizeof(list));
		graph[v2 - 1].adj_list->data = &graph[v1 - 1];
		graph[v2 - 1].adj_list->prev = NULL;
		graph[v2 - 1].adj_list->next = NULL;
	}
	else
	{
		list *cur = graph[v2 - 1].adj_list;
		while (cur != NULL)
		{
			if (graph[v1 - 1].vertax == cur->data->vertax)
				break;
			if (graph[v1 - 1].vertax < cur->data->vertax)
			{
				list *temp = (list*)malloc(sizeof(list));
				temp->data = &graph[v1 - 1];
				if (cur->prev == NULL)
				{
					temp->next = cur;
					temp->prev = NULL;
					cur->prev = temp;
					graph[v2 - 1].adj_list = temp;
				}
				else
				{
					temp->next = cur;
					temp->prev = cur->prev;
					cur->prev->next = temp;
					cur->prev = temp;
				}
				break;
			}
			if (graph[v1 - 1].vertax > cur->data->vertax)
			{
				if (cur->next == NULL)
				{
					list *temp = (list*)malloc(sizeof(list));
					temp->data = &graph[v1 - 1];
					cur->next = temp;
					temp->prev = cur;
					temp->next = NULL;
					break;
				}
				else
				{
					if (graph[v1 - 1].vertax < cur->next->data->vertax)
					{
						list *temp = (list*)malloc(sizeof(list));
						temp->data = &graph[v1 - 1];
						temp->prev = cur;
						temp->next = cur->next;
						cur->next->prev = temp;
						cur->next = temp;
						break;
					}
				}
			}
			cur = cur->next;
		}
	}
	
}