#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct stack stack;
struct stack
{
	char s;
	stack * prev;
	stack * next;
};
int main()
{
	int num,i,j;
	char arr[51];
	stack *end;
	int result;

	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		end = NULL;
		result = 1;
		scanf("%s", arr);
		for (j = 0;j<strlen(arr); j++)
		{
			if (*(arr + j) == '(')
			{
				stack * temp = (stack*)malloc(sizeof(stack));
				temp->s = *(arr + j);
				temp->prev = NULL;
				temp->next = NULL;
				if (end == NULL) end = temp;
				else
				{
					temp->prev = end;
					end->next = temp;
					end = temp;
				}
			}
			else
			{
				stack *temp;
				if (end == NULL)
				{
					result = 0;
					break;
				}
				temp = end->prev;
				if (temp != NULL)
				{
					temp->next = NULL;
					free(end);
					end = temp;
				}
				else
				{
					free(end);
					end = NULL;
				}
				
			}
		}
		if (end != NULL)
		{
			stack *cur = end;
			result = 0;
			while (cur != NULL)
			{
				stack *temp;
				temp = cur->prev;
				if (temp != NULL)
					temp->next = NULL;
				free(cur);
				cur = temp;
			}
		}
		
		if (result == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}