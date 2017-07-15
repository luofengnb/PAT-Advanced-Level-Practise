#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;
int closeTime=17*60*60,openTime=8*60*60;
struct peo{
	int arriveTime,startTime,processTime,doneTime;
};
struct cmp1{	bool operator()(const peo &a,const peo &b)const{
		return a.arriveTime>b.arriveTime;
	}
};
struct cmp2{	bool operator()(const peo &a,const peo &b)const{
		return a.doneTime>b.doneTime;
	}
};
int main(){_
	#ifdef INPUT
	freopen("data.in","r",stdin);
	#endif
    unsigned int peopleNum,windowsNum;
	cin>>peopleNum>>windowsNum;
	priority_queue<peo,vector<peo>,cmp1> wait;
	priority_queue<peo,vector<peo>,cmp2> service;
	int hour,minute,second;
	char useless;
	for(unsigned int i=0;i<peopleNum;i++){
		peo p;
		cin>>hour>>useless>>minute>>useless>>second>>p.processTime;
		p.arriveTime=hour*60*60+minute*60+second;
		if(p.arriveTime>closeTime)	continue;
		wait.push(p);
	}
	int serviceNum=wait.size(),sumWaitTime=0;
	int leaveTime=openTime;
	while(!wait.empty()){//等待队列未空 
		while(service.size()<windowsNum){//窗口没满
			if(!wait.empty()){
				peo current=wait.top();
				current.startTime=max(leaveTime,current.arriveTime);//开始服务的时间=MAX（自己到达的时间 ,窗口空出的时间） 
				current.doneTime=current.startTime+current.processTime*60;
				sumWaitTime+=current.startTime-current.arriveTime;
				wait.pop();			
				service.push(current);
			}
			else break;
		}
		leaveTime=service.top().doneTime;
		service.pop();//每次服务完一个人 
	}
    cout<<setprecision(1)<<fixed<<sumWaitTime*1.0/serviceNum/60;
    return 0;
}
