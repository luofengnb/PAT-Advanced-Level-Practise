#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <sstream> 
#include <algorithm>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int c = a + b;
	if(fabs(c)<1000)	cout<<c;
	else
	{
		if(c<0)	
		{
			cout<<'-';
			c=-c;
		}
		string s;
		stringstream stream;	//dec c++不支持to_string() 
		stream<<c;
		stream>>s;
		reverse(s.begin(),s.end());	//从个位开始数 
		stack <char> ans;
		int i=1;
		for(auto j = s.begin() ;j!=s.end() ; j++,i++)
		{
			ans.push(*j);
			if(i%3==0&&((j+1)!=s.end()))	 //每3位加逗号，且最后三位（若正好）不用加 
				ans.push(',');	 
		}
		while(!ans.empty())
		{
			cout<<ans.top();
			ans.pop();
		}	
	} 
	return 0; 
} 
