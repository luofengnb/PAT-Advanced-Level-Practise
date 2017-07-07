#include<iostream>
using namespace std;
int main()
{
	int begin=0,end=0,sum=-1,n;
	int temp_begin=0,temp_end=0,temp_sum=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0;i<n;i++){
		if(temp_sum<0){
			temp_begin=i;
			temp_end=i;
			temp_sum=a[i]; 
		}
		else{
			temp_end=i;
			temp_sum+=a[i];
		}
		if(temp_sum>sum){
			begin=temp_begin;
			end=temp_end;
			sum=temp_sum;
		}
	}
	if(sum<0) cout<<0<<" "<<a[0]<<" "<<a[n-1];
	else cout<<sum<<" "<<a[begin]<<" "<<a[end];
	return 0;
}
/*Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
