#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string str, str2;
	cin >> str;
	auto b = str.begin() , e = str.end() ;
	int jinwei = 0;
	do
	{
		--e;
		int temp = (*e - 48) * 2, yushu = (temp + jinwei) % 10;
		str2.push_back(yushu + 48);
		jinwei = temp / 10;
	}
	while(e != b);
	if(jinwei != 0)	str2.push_back(jinwei + 48);//如果有进位，别忘了 
	reverse(str2.begin() , str2.end() );
	string s = str2;
	sort(str.begin() , str.end() );
	sort(str2.begin() , str2.end() );
	if(str == str2)	cout << "Yes" << endl;
	else	cout << "No" << endl;
	cout << s;
	return 0;
}
