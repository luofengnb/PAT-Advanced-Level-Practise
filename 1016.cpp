#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;
struct date{
	int month;
	int day;
	int hour;
	int minute;
	//重载<对date的支持 
	//重载>>对date的支持 
};
struct peo{
	string name;
	date time;
	string line;
};
int cmp(peo &a,peo &b){
	if(a.name==b.name )
		return a.time<b.time;	
	return a.name<b.name; 
} 
int weight[24];
int main(){_
	#ifdef INPUT
	freopen("data.in","r",stdin);
	#endif
    for(int i=0;i<24;i++){
    	cin>>weight[i]; 
	}
    int n;
    vector <peo> p;
    while(n--){
    	peo temp;
    	cin>>temp.name>>temp.time>>time.line;
		p.push_back(temp); 
	}
	sort(p.begin(),p.end(),cmp);
	string current_name=NULL;
	int on_line_tag=0;
	double amount=0;
	for(auto it=p.begin();;it!=p.end();it++){
		if((*it).name!=current_name){
			cout<<"Total amount: $"<<setprecision(2)<<fixed<<amount<<"\n";
			on_line_tag=0;
			current_name=(*it).name;
			amount=0;
			cout<<current_name<<" "<<(*it).time.month<<"\n";
		}
		else{
			if((*it).line=="on-line")
				on_line_tag=1;
			else{
				if(on_line_tag==1){
					//计算两个时间点的时间差，以及花费 
					
					//输出此项
					on_line_tag=0; 
				}
				
			}
		}
	} 
    return 0;
}

