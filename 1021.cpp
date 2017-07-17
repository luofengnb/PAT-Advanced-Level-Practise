#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define UNLINk 99999999 
using namespace std;
int p[10001];
int find(int x){return p[x]==x?x:p[x]=find[p[x]];} 
int main(){_
	#ifdef INPUT
	freopen("data.in","r",stdin);
	#endif
    int N;
    cin>>N;
    vector<vector<int>> a(N+1,vector<int>(N+1,UNLINK));
    for(int i=0,m,n;i<N-1;i++){
    	cin>>m>>n;
    	a[m][n]=a[n][m]=1;
	}
    for(int i=1;i<=N;i++)	p[i]=i;
    return 0;
}
