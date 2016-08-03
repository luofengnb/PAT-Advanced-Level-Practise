#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N, b;
	cin >> N >> b;
	vector <int> a;
	if(N == 0)	a.push_back(0);
	while(N != 0)
	{
		a.push_back(N % b);
		N = N / b;
	}
	auto a2 = a;
	reverse(a2.begin(), a2.end());
	auto i = a.begin(), end = a.end();
	for(auto j = a2.begin(); i != end; ++i, ++j)
	{
		if(*i != *j)	break;
	}
	if(i == end)	cout << "Yes" << endl;
	else	cout << "No" << endl;
	auto begin = a2.begin();
	cout << *begin;
	for(++begin; begin != a2.end(); ++begin)
		cout << " " << *begin;
	return 0;
}
