#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;
int Answer;
int main(int argc, char ** argv)
{
	int T, test_case;
	freopen("input","r",stdin);
	cin>>T;
	for(test_case =0; test_case<T; test_case++)
	{
		int num;
		map<int, int> arr;
		map<int, int>::iterator it;
		cin>>num;
		for(int i =0; i<num;i++)
		{
			int temp;
			cin>>temp;
		
			if((it=arr.find(temp))!=arr.end())
			{
				it->second++;
			}
			else
			{
				arr.insert(pair<int,int>(temp,1));
			}
		}
		
		Answer = 0 ;
		
		vector<int> arr_result;

		for(it = arr.begin();it != arr.end();)
		{
			if(it->second%2==1)
			{
				int temp=it->first;
				arr_result.push_back(temp);
			}
			arr.erase(it++);
		}

		vector<int>::iterator it_vec=arr_result.begin();
		Answer=*it_vec;
		it_vec++;
		for(;it_vec!=arr_result.end();it_vec++)
		{
			Answer ^=*it_vec;
		}
		
		

		
		cout << "Case #" <<test_case+1 <<endl;
		cout << Answer << endl;
	}

	return 0;
}
