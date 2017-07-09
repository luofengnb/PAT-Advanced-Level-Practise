#include<iostream>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cmath> 
using namespace std;
int f(char c){
	if(isdigit(c)) return c-48;
	if(isalpha(c)) return c-87;
}
long long conversion(string a,int radix){
	long long ans=0;
	for(int exp=a.length()-1,i=0;exp>=0;exp--,i++){
		ans+=f(a[i])*pow(radix,exp);
	}
	return ans;
}
int main()
{
	vector<string> a(3);
	long long tag,radix,radix2=0;
	cin>>a[1]>>a[2]>>tag>>radix;
	long long ans=conversion(a[tag],radix);
	long long left=0,right;
	for(auto e:a[3-tag]){
		if(e>left)
			left=e;
	}
	if(left>=97) left=left-87+1;
	else left=left-48+1;
	right=ans>left?ans:left;
/*	long long temp;
	while((temp=conversion(a[3-tag],left))<=ans){
		if(temp==ans){
			radix2=left;
			break;
		}	
		else left++;
	}*/
	long long ans2,temp,mid;
	while(left<=right){
		mid=(left+right)/2;
		ans2=conversion(a[3-tag],mid);
		temp=ans2-ans;
		if(temp>0||ans2<0) right=mid-1;	//判断ans<0很重要，10个case 
		else if(temp<0) left=mid+1;
		else{
			radix2=mid;
			break;
		}
	}
	if(radix2)	cout<<radix2;
	else cout<<"Impossible";
	return 0; 
} 
/*
Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/
