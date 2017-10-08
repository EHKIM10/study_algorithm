#include <iostream>
#include <map>

using namespace std;

int main(void)
{

	map<int,int> m;
	map<int,int>::iterator it;
	m.insert(pair<int,int>(3,4));
	if((it=m.find(3))!=m.end())
	{
		cout<<"found"<<endl;
		cout<<it->second<<endl;
	}
	else
	{
		cout<<"nope"<<endl;
	}
	return 0;

}
