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
		stringstream stream;	//dec c++��֧��to_string() 
		stream<<c;
		stream>>s;
		reverse(s.begin(),s.end());	//�Ӹ�λ��ʼ�� 
		stack <char> ans;
		int i=1;
		for(auto j = s.begin() ;j!=s.end() ; j++,i++)
		{
			ans.push(*j);
			if(i%3==0&&((j+1)!=s.end()))	 //ÿ3λ�Ӷ��ţ��������λ�������ã����ü� 
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
