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
	int num, i, j;
	char arr[51];
	stack *end;
	int result,result2=0,cnt=0,prev_cnt=0;


	end = NULL;
	result = 1;
	scanf("%s", arr);
	for (j = 0; j<strlen(arr); j++)
	{
		if (*(arr + j) == '(')
		{				
			stack * temp = (stack*)malloc(sizeof(stack));
			temp->s = *(arr + j);
			temp->prev = NULL;				temp->next = NULL;
			if (end == NULL)
			{
				end = temp;
				prev_cnt = 0;
			}
			else
			{
				temp->prev = end;
				end->next = temp;
				end = temp;
			}
			cnt++;

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
			
			if (prev_cnt == 0 && cnt == 1)
				result2 += 2;
			else if (prev_cnt == 0 && cnt > 1)
				result2 = 2;
			else
			{
				if (cnt == prev_cnt)
					result2 += 2;
				else if(cnt<prev_cnt)
					result2 *= 2;
				
			}
			prev_cnt = cnt;
			cnt--;
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
	if (result == 0)
		printf("0\n");
	else
		printf("%d\n", result2);

	return 0;
}