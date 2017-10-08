#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int Answer;
int main(int argc, char ** argv)
{
	int T, test_case;
	freopen("input","r",stdin);
	cin>>T;
	for(test_case=0;test_case<T;test_case++)
	{
		Answer =0;
		int num_candidates;
		cin>>num_candidates;

		multiset<int> points;
		for(int i =0 ; i<num_candidates;i++)
		{
			int temp;
			cin>>temp;
			points.insert(temp);
		}
		
		multiset<int>::reverse_iterator r_it;
		r_it=points.rbegin();

		multiset<int>::iterator it;
		for(it=points.begin();it!=points.end();it++)
		{
			cout<<*it<<endl;
			int diff = *r_it-*it;
			if(diff<num_candidates)
				Answer++;
		}


		cout<<"Case #"<< test_case+1<<endl;
		cout<<Answer<<endl;
	}
	return 0;

}
