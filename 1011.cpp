#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int N = 3;
	double ans = 1;
	while(N--)
	{
		double W, T, L;
		cin >> W >> T >> L;
		double maxnum = max(max(W, T), max(T, L));
		if(fabs(W - maxnum) < 1e-8)
		{
			ans *= W;
			cout << "W ";
		}
		else if(fabs(T - maxnum) < 1e-8)
		{
			ans *= T;
			cout << "T ";
		}
		else
		{
			ans *= L;
			cout << "L ";
		}
	}
	ans = (ans * 0.65 - 1) * 2;
	printf("%.2lf", ans);
	return 0;
}
