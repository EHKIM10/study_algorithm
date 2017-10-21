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
int cnt=0,prev_cnt=0,result=1;
stack* push(char value, stack *s);
stack* pop(stack *s);
int main()
{
	int num, i, j;
	char arr[51];
	stack *end;
	int result, result2 = 0,result_temp=0,temp=0;
	

	end= NULL;
	scanf("%s", arr);
	for (j = 0; j<strlen(arr); j++)
	{
		if (*(arr + j) == '('|| *(arr + j) == '[')
		{
			end = push(*(arr + j),end);
		}
		else if (*(arr + j) == ')')
		{
			if (end->s != '(')
			{
				result = 0;
				break;
			}
			end = pop(end);
			if (prev_cnt == 0 && cnt == 1)
				result2 += 2;
			else if (prev_cnt == 0 && cnt > 1)
				result2 = 2;
			else if (prev_cnt ==1 && cnt > prev_cnt)
					result_temp = 2;
			else if (prev_cnt > 1 && cnt > prev_cnt)
			{
				result_temp = 2;
				temp = prev_cnt;
			}
			else if (result_temp != 0)
			{
				if (cnt == prev_cnt)
					result_temp += 2;
				else if (cnt<prev_cnt)
					result_temp *= 2;
				if (end == NULL || cnt == temp)
				{
					result2 += result_temp;
					result_temp = 0;
					temp = 0;
				}
			}
			else
			{
				if (cnt == prev_cnt)
					result2 += 2;
				else if (cnt<prev_cnt)
					result2 *= 2;

			}
			prev_cnt = cnt;
			cnt--;
			
		}
		else if (*(arr + j) == ']')
		{
			if (end->s != '[')
			{
				result = 0;
				break;
			}
			end = pop(end);
			if (prev_cnt == 0 && cnt == 1)
				result2 += 3;
			else if (prev_cnt == 0 && cnt > 1)
				result2 = 3;
			else if (prev_cnt == 1 && cnt > prev_cnt)
					result_temp = 3;
			else if (prev_cnt > 1 && cnt > prev_cnt)
			{
					result_temp = 3;
					temp = prev_cnt;
			}
			else if (result_temp != 0)
			{
				if (cnt == prev_cnt)
					result_temp += 3;
				else if (cnt<prev_cnt)
					result_temp *= 3;
				if (end == NULL||cnt==temp)
				{
					result2 += result_temp;
					result_temp = 0;
					temp = 0;
				}
			}
			else
			{
				if (cnt == prev_cnt)
					result2 += 3;
				else if (cnt<prev_cnt)
					result2 *= 3;
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
stack* pop(stack *s)
{
	stack *temp;
	if (s == NULL)
	{
		result = 0;
		return NULL;
	}
	temp = s->prev;

	if (temp != NULL)
	{
		temp->next = NULL;
		free(s);
		s = temp;
	}
	else
	{
		free(s);
		s = NULL;
	}
	return s;
}
stack* push(char value, stack *s)
{
	stack * temp = (stack*)malloc(sizeof(stack));
	temp->s = value;
	temp->prev = NULL;				
	temp->next = NULL;
	if (s == NULL)
	{
		s = temp;
	}
	else
	{
		temp->prev = s;
		s->next = temp;
		s = temp;
	}
	cnt++;
	return s;
}