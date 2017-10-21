#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct stack stack;
struct stack
{
	int x;
	stack * prev;
	stack * next;
};

int main()
{
	stack *start = NULL;
	stack *end = NULL;
	int num, i,value,cnt=0;
	char cmd[10];
	scanf("%d",&num);
	for (i = 0; i < num; i++)
	{
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0)
		{
			stack *temp = (stack*)malloc(sizeof(stack));
			cnt++;
			scanf("%d", &value);
			temp->x = value;
			temp->next = NULL;
			temp->prev = NULL;
			if (start == NULL)
			{
				start = end = temp;
			}
			else
			{
				end->next = temp;
				temp->prev = end;
				end = temp;
			}
		}
		else if (strcmp(cmd, "pop") == 0)
		{
			if (end == NULL)
				printf("-1\n");
			else
			{
				stack *temp=end->prev;
				cnt--;
				printf("%d\n",end->x);
				if(temp!=NULL)
					temp->next = NULL;
				free(end);
				end = temp;
			}
		}
		else if (strcmp(cmd, "size") == 0)
		{
			printf("%d\n", cnt);
		}
		else if (strcmp(cmd, "empty") == 0)
		{
			if (end == NULL)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(cmd, "top") == 0)
		{
			if (end == NULL)
				printf("-1\n");
			else
			{
				printf("%d\n", end->x);
			}
		}
		else break;
	}

	if (end != NULL)
	{
		stack * cur = end;
		while (cur != NULL)
		{
			stack *temp = cur->prev;
			if (temp != NULL)
				temp->next = NULL;
			free(cur);
			cur = temp;
		}
	}

	return 0;
}