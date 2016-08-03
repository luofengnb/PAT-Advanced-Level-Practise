#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string s;
	vector <string> f={"zero","one","two","three","four","five","six","seven","eight","nine"};
	cin>>s;
	int sum = 0;
	for(auto c:s)
		sum+=(c-48);
	string s2=to_string(sum);
	auto beg=s2.begin(),end=s2.end();
	cout<<f[*beg-48];
	for(++beg;beg!=end;++beg)
		cout<<" "<<f[*beg-48];
	return 0;
}
