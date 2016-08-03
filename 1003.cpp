#include <iostream>
#include <vector>
using namespace std;
int min1=99999999,maxpeople=0,N,cnt=0,end1,book[1000]={0},people[1000]={0},a[1000][1000]; 
void dfs(int cur,int dis,int peo)
{
	if(cur==end1)
	{
		if(dis<min1)
		{
			cnt=1;
			min1=dis;
			maxpeople=peo;
		}
		else if(dis==min1)
		{
			++cnt;
			if(peo>maxpeople)	maxpeople=peo;	
		}		
		return;
	}
	if(dis>min1) return;
	for(int j = 0;j < N;j++)
	{
		if(a[cur][j]!=99999999 && book[j]==0)
		{
			book[j]=1;
			dfs(j,dis+a[cur][j],peo+people[j]);
			book[j]=0;
		} 
	}
	return;
}
int main()
{
	int M,begin1;
	cin>>N>>M>>begin1>>end1;
	for(int i = 0;i < N;i++)	//二维数组初始化 
		for(int j = 0;j < N;j++)
			if(i==j) a[i][j]=0;
			else a[i][j]=99999999;
	for(int i = 0;i < N;i++) //每个城市救援队人数 
		cin>>people[i];
	int c1,c2,L,m=M;
	while(m--)
	{
		cin>>c1>>c2>>L; 
		a[c1][c2]=a[c2][c1]=L;
	}
	book[begin1]=1;
	maxpeople=people[begin1];
	dfs(begin1,0,maxpeople);
	cout<<cnt<<" "<<maxpeople;
	return 0;
}
