#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct deque deque;
struct deque
{
	int x;
	deque * prev;
	deque * next;
};
int cnt = 0;
deque* push_back(int v, deque *d);
deque* push_front(int v, deque *d);
deque* pop_back(deque *d);
deque* pop_front(deque *d);
int main()
{
	int N,i,value;
	char cmd[15];
	deque *front;
	deque *end;
	front = end = NULL;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s",cmd);
		if (strcmp(cmd, "push_back") == 0)
		{
			scanf("%d", &value);
			if (end == NULL)
			{
				front = end = push_back(value,end);
			}
			else
				end = push_back(value, end);
		}
		else if (strcmp(cmd, "push_front") == 0)
		{
			scanf("%d", &value);
			if (front == NULL)
				end = front = push_front(value, front);
			else
				front = push_front(value, front);
		}
		else if (strcmp(cmd, "pop_back") == 0)
		{
			end = pop_back(end);
			if (cnt == 0)
				front = end;
		}
		else if (strcmp(cmd, "pop_front") == 0)
		{
			front = pop_front(front);
			if (cnt == 0)
				end = front;
		}
		else if (strcmp(cmd, "size") == 0)
		{
			printf("%d\n",cnt);
		}
		else if (strcmp(cmd, "empty") == 0)
		{
			if (end == NULL)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(cmd, "back") == 0)
		{
			if (end == NULL)
				printf("-1\n");
			else
				printf("%d\n",end->x);
		}
		else if (strcmp(cmd, "front") == 0)
		{
			if (front == NULL)
				printf("-1\n");
			else
				printf("%d\n",front->x);
		}
		else
			break;
	}
	if (end != NULL)
	{
		deque* cur = end;
		while (cur != NULL)
		{
			deque* temp = cur->prev;
			if (temp != NULL)
				temp->next = NULL;
			free(cur);
			cur = temp;
		}
	}
	return 0;
}
deque* push_back(int v, deque *d)
{
	deque *temp = (deque*)malloc(sizeof(deque));
	temp->next = NULL;
	temp->prev = NULL;
	temp->x = v;
	if (d == NULL)
	{
		d = temp;
	}
	else
	{
		d->next = temp;
		temp->prev = d;
		d = temp;
	}
	cnt++;
	return d;
}
deque* push_front(int v, deque *d)
{
	deque *temp = (deque*)malloc(sizeof(deque));
	temp->next = NULL;
	temp->prev = NULL;
	temp->x = v;
	if (d == NULL)
	{
		d = temp;
	}
	else
	{
		d->prev = temp;
		temp->next = d;
		d = temp;
	}
	cnt++;
	return d;
}
deque* pop_back(deque *d)
{
	if (d == NULL)
		printf("-1\n");
	else
	{
		deque *temp = d->prev;
		printf("%d\n", d->x);
		if (temp != NULL)
			temp->next = NULL;
		free(d);
		d = temp;
		cnt--;
	}
	return d;
}
deque* pop_front(deque *d)
{
	if (d == NULL)
		printf("-1\n");
	else
	{
		deque *temp = d->next;
		printf("%d\n", d->x);
		if (temp != NULL)
			temp->prev = NULL;
		free(d);
		d = temp;
		cnt--;
	}
	return d;
}