#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;
struct date{
	int month;
	int day;
	int hour;
	int minute;
	bool operator <(const date &b) const{	//重载<对date的支持 
		if(day==b.day){
			if(hour==b.hour){
				return minute<b.minute;
			}
			else return hour<b.hour;
		}
		else return day<b.day;
	}
};

istream& operator >>(istream &in,date &x){	//重载>>对date的支持 
		char useless;
		in>>x.month>>useless>>x.day>>useless>>x.hour>>useless>>x.minute;
		return in; 
	}
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
int cost(const date &before,const date & after,int &amount){
	int before_minute,after_minute,before_amount=0,after_amount=0;
	before_minute=before.hour*60+before.minute;
	after_minute=(after.day-before.day)*24*60+after.hour*60+after.minute;
	for(int time=before_minute,i=0;time>0;i++){
		if(time>=60){
			before_amount+=60*weight[i];
			time-=60;
		}
		else{
			before_amount+=time*weight[i];
			time=0;
		}
	}
	for(int time=after_minute,i=0;time>0;i++){
		i=i%24;
		if(time>=60){
			after_amount+=60*weight[i];
			time-=60;
		}
		else{
			after_amount+=time*weight[i];
			time=0;
		}
	}
	amount=after_amount-before_amount;
	return after_minute-before_minute; 
}
int main(){_
	#ifdef INPUT
	freopen("data.in","r",stdin);
	#endif
    for(int i=0;i<24;i++){
    	cin>>weight[i]; 
	}
    int n;
    cin>>n;
    vector <peo> p;
    while(n--){
    	peo temp;
    	cin>>temp.name>>temp.time>>temp.line;
		p.push_back(temp); 
	}
	sort(p.begin(),p.end(),cmp);
	string current_name=p[0].name,outputedName;
	int on_line_tag=p[0].line=="on-line"?1:0;
	date before,after;
	if(on_line_tag)	before=p[0].time;
	int amount,sum=0,lastTime;
	for(auto it=p.begin()+1;it!=p.end();it++){
		if((*it).name!=current_name){//下一条记录的用户名不同 
			if(sum>0)
			cout<<"Total amount: $"<<setprecision(2)<<fixed<<sum*1.0/100<<"\n";
			on_line_tag=0;
			sum=0;
			current_name=(*it).name;
			if((*it).line=="on-line"){
					on_line_tag=1;
					before=(*it).time;
			}
		}
		else{
			if((*it).line=="on-line"){
				on_line_tag=1;
				before=(*it).time;
			}
			else{
				if(on_line_tag==1){
					//计算两个时间点的时间差，以及花费 
					after=(*it).time;
					lastTime=cost(before,after,amount);
					sum+=amount;
					if(current_name!=outputedName){
						cout<<current_name<<" "<<setfill('0')<<setw(2)<<(*it).time.month<<"\n";
						outputedName=current_name;
					}					
					cout<<setfill('0')<<setw(2)<<before.day<<":"<<setw(2)<<before.hour<<":"<<setw(2)<<before.minute<<" ";
					cout<<setfill('0')<<setw(2)<<after.day<<":"<<setw(2)<<after.hour<<":"<<setw(2)<<after.minute<<" ";
					cout<<lastTime<<" $"<<setprecision(2)<<fixed<<amount*1.0/100<<"\n";
					//输出此项
					on_line_tag=0; 
				}				
			}
		}
	}
	if(sum)
	cout<<"Total amount: $"<<setprecision(2)<<fixed<<sum*1.0/100<<"\n";
    return 0;
}

