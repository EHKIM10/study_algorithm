#include <string>
#include <stdlib.h>
#include <iostream>
#define queue_max 8

using namespace std;
int main(void)
{
	int num[queue_max];
	int i=8;
	int *head=&num[0],*tail=&num[0];
	while(1)
	{
		cout<<"input number: ";
		cin>>*tail;
		cout<<*tail<<endl;
		i--;
		if(*tail==0)
		{
			cout<<'['<<*head<<']'<<endl;
			head+=4;
			cout<<"[next]"<<*head<<endl;
			i++;
		}
		tail+=4;
		if(i==0)
			break;	
	}
	return 0;

}
