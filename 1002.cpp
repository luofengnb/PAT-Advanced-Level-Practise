#include <iostream>
#include <cmath> 
using namespace std;
int main() //不能认为小于0.1的数不输出！ 
{
	double a[1005]={0};
	int N=2;
	while(N--)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int i;
			double j;
			cin>>i>>j;
			a[i]+=j; 
		}
	}
	int x = 0;
	for(auto c : a)
		if(fabs(c)>1e-8)	x++;	
	cout<<x;
	for(int i = 1004;i >= 0;i--)
	{
		cout.precision(1);
		if(fabs(a[i])>1e-8)	
			cout<<fixed<<" "<<i<<" "<<a[i];
	}		
	return 0;
}
