#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define UNLINk 99999999 
using namespace std;
int p[10001],visit[10001],b[10001]={0},maxlength,N;
struct Edge{
	int x,y;
};
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void Union(int x,int y){
	int xf=find(x),yf=find(y);
	p[xf]=yf;
}
void dfs(vector<vector<int>> &a,int point,int length){
	//判断边界
	if(visit[point]==1) return;
	visit[point]=1;
	length++;
	for(int i=1;i<=N;i++){
		if(a[point][i]==1){
			dfs(a,i,length);
		}
		if(length-1>maxlength) maxlength=length-1;
	}
	cout<<"point="<<point<<" maxlength="<<maxlength<<endl;
	b[point]=maxlength;
}
int main(){_
	#ifdef INPUT
	freopen("data.in","r",stdin);
	#endif
    //int N;
    cin>>N;
    Edge edge[N];
    vector<vector<int>> a(N+1,vector<int>(N+1,UNLINk));
    for(int i=1,m,n;i<N;i++){
    	cin>>m>>n;
    	a[m][n]=a[n][m]=1;
    	edge[i].x=m;
    	edge[i].y=n;
	}
	//判断连通子图个数 
    for(int i=1;i<=N;i++)	p[i]=i;
    for(int i=1;i<N;i++){
    	if(find(edge[i].x)!=find(edge[i].y))	
			Union(edge[i].x,edge[i].y); 
	}
	int ans=0;
	for(int i=1;i<=N;i++){
		if(p[i]==i) ans++;
	}
	if(ans>1){
		cout<<"Error: "<<ans<<" components";
		return 0;
	}
	//判断是否有环
	for(int i=1;i<=N;i++)	p[i]=i;
    for(int i=1;i<N;i++){
    	if(find(edge[i].x)!=find(edge[i].y))	
			Union(edge[i].x,edge[i].y);
		else{
			cout<<"Error: 1 components";
			return 0;
		} 
	}
	int Max=0;
	for(int i=1;i<=N;i++){//对每个点调用dfs函数，求出最长距离，保存在b[point]=maxlenght
		memset(visit,0,sizeof(visit));
		//for(int j=0;j<N+1;j++) cout<<"visit["<<j<<"]="<<visit[j]<<endl;
		maxlength=-99999999;
		dfs(a,i,0);
		if(b[i]>Max) Max=b[i];
		//cout<<"b["<<i<<"]="<<b[i]<<endl; 
	}
	//for(int e:b) cout<<e<<endl;
	//cout<<"b["<<1<<"]="<<b[1]<<endl; 
	vector<int> c;
	//cout<<"Max="<<Max<<endl;
	for(int i=1;i<=N;i++){
	//	cout<<"b["<<i<<"]="<<b[i]<<endl; 
		if(b[i]==Max)
			c.push_back(i);
	} 
	//sort(c.begin(),c.end());
	for(int e:c) cout<<e<<endl;
    return 0;
}
