#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int is_primer(int a)	//û�����������ʵҪ�ų�a=1��a=0���������
{
	if(a == 0 || a == 1)	return 0;
	int i, m = sqrt(a) + 0.5;
	for( i = 2; i <= m; i++)
		if(a % i == 0)	break;
	if(i > m)	return 1;
	return 0;
}
int main()
{
	int num;
	while(cin >> num && num > 0)
	{
		int radix;
		cin >> radix;
		if(is_primer(num))
		{
			vector <int> s;
			while(num != 0)	//������ؿ���һ��ѭ��������õ�������sum = sum*num+num%radix; num/=radix;��
			{
				s.push_back(num % radix);
				num /= radix;
			}
			int m = s.size(), sum = 0;
			for(auto c : s)
			{
				sum += c * pow(radix, --m);
			}
			if(is_primer(sum))	cout << "Yes" << endl;
			else	cout << "No" << endl;
		}
		else	cout << "No" << endl;
	}
	return 0;
}
