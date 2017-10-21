
#include <stdio.h>

int Answer;
unsigned long long arr[2000003];
const long long Divisor = 1000000007;
void factorial(unsigned long long v)
{
	unsigned long long i;
	for (i = 0; i <= v; i++)
	{
		if (i)
			arr[i] = (arr[i - 1] * i) % Divisor;
		else
			arr[0] = 1;
	}
}
int main(void)
{
	int T, test_case, N, M, i, j, temp;
	factorial(2000002);
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		scanf("%d%d", &N, &M);
		Answer = arr[N + M + 2] / (arr[N + 1] * arr[M + 1]) - 1;

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}