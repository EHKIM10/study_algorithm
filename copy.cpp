#include <iostream>
#include <deque>
#include <vector>
#include <iterator>
#include <set>
using namespace std;
int main()
{
	int arr[]={30,20,50,60,80,10,70};
	vector<int> vec1(&arr[0],&arr[7]);
	deque<int> dq;
	deque<int>::iterator it;
	copy(vec1.begin(),vec1.end(),back_inserter(dq));
	for(it=dq.begin();it!=dq.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	set<int> set1;
	set<int>::iterator it2=set1.begin();
	copy(vec1.begin(),vec1.end(),inserter(set1,it2));
	set<int>::iterator it3;
	for(it3=set1.begin();it3!=set1.end();it3++)
	{
		cout<<*it3<<" ";
	}
	cout<<endl;
	return 0;
}
