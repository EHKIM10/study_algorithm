#include <stdio.h>

int Answer;
int factorial(int value)
{
    if(value==1||value==0)
        return 1;
    else value*factorial(value-1);
}
int main(void)
{
	int T, test_case,N,M,i,j,temp;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer=0;
		scanf("%d%d",&N,&M);
		for(i=1;i<=N;i++)
		{
		    for(j=1;j<=M;j++)
		    {
		        temp=factorial(i+j)/factorial(i)*factorial(j);
		        Answer+=temp;
		    }
		}
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
	}

	return 0;//Your program should return 0 on normal termination.
}