#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;
struct peo{
	int hour,minute,second,processTime;
	bool operator <(const peo &b)const{
	if(hour==b.hour){
		if(minute==b.minute)
			return second>b.second;
		return minute>b.minute;
	}
	return hour>b.hour;
	}
};
int main(){_
	#ifdef INPUT
	freopen("data.in","r",stdin);
	#endif
    int peopleNum,windowsNum;
	cin>>peopleNum>>windowsNum;
	peo p;
	priority_queue<peo> pq;
	char useless; 
	for(int i=0;i<peopleNum;i++){
		cin>>p.hour>>useless>>p.minute>>useless>>p.second>>p.processTime;
		pq.push(p);
	}
/*
while(!pq.empty()){
		cout<<setfill('0')<<setw(2)<<pq.top().hour<<":"<<setw(2)<<pq.top().minute<<":"<<setw(2)<<pq.top().second<<endl;
		pq.pop();
	}
*/	
//	sort(p.begin(),p.end(),cmp);
	
    
    return 0;
}
