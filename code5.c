#include <stdio.h>
#include <malloc.h>
long long Answer = 0;
long long solve(char *input, int N, int K)
{
	int arr[200000];
	int i, j, k = 1, h;
	long long sum;
	for (i = 0; i < N; i++)
	{
		for (j = 0, h = i; j <= i; j++, h--)
		{
			if (i % 2 == 0)//even
				arr[h*(N)+j] = k++;
			else //odd
				arr[j*(N)+h] = k++;
		}
	}
	for (i = 1; i < N; i++)
	{
		for (j = N - 1, h = i; h < N; j--, h++)
		{
			if (i % 2 == 0)//even
				arr[j*(N)+h] = k++;
			else //odd
				arr[h*(N)+j] = k++;
		}
	}
	sum = 1;
	j = h = 0;
	for (i = 0; i<K; i++)
	{
		//printf("%c", *(input + i));
		if (*(input + i) == 'U')
			--j;
		else if (*(input + i) == 'D')
			++j;
		else if (*(input + i) == 'L')
			--h;
		else if (*(input + i) == 'R')
			++h;
		else
			break;
		sum += arr[j*(N)+h];
	}


	return sum;
}
int main(void)
{
	int T, test_case, N, K;
	char *input;

		freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		setbuf(stdout, NULL);
		scanf("%d%d", &N, &K);

		input = (char*)malloc(sizeof(char)*K + 1);
		setbuf(stdout, NULL);
		scanf("%s", input);
		printf("%s", input);
		setbuf(stdout, NULL);

		Answer = solve(input, N, K);
		free(input);
		input = NULL;
		printf("Case #%d\n", test_case + 1);
		printf("%lld\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}