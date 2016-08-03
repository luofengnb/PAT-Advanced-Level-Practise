#include <iostream>
using namespace std;
int main()
{
	int N,nowfloor = 0,nextfloor,sum = 0;
	cin>>N;
	while(N--)
	{
		cin>>nextfloor;
		if(nextfloor>nowfloor)	sum+=(nextfloor-nowfloor)*6;
		else	sum+=(nowfloor-nextfloor)*4;
		sum+=5;
		nowfloor=nextfloor;
	}
	cout<<sum;
	return 0;
}
