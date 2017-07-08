#include<iostream>
#include<list>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
struct node{
	int exp;
	double coe;
};
int main()
{
	vector<list<node> > p;
	for(int i=0;i<2;i++){	
		int m;
		cin>>m;
		list<node> listemp;
		while(m--){
			node temp;
			cin>>temp.exp>>temp.coe;
			listemp.push_back(temp);
		}
		p.push_back(listemp);
	}
	vector<double> a(1000000,0);
	for(auto it1=p[0].begin();it1!=p[0].end();it1++){
		for(auto it2=p[1].begin();it2!=p[1].end();it2++){
			int Exp;
			double Coe;
			Coe=(*it1).coe*(*it2).coe;
			Exp=(*it1).exp+(*it2).exp;
			a[Exp]+=Coe;
		}
	}
	int cnt=0;
	for(auto e:a)	if(fabs(e)>1e-6) cnt++;
	cout<<cnt<<" ";
	for(int i=1000000;i>=0;i--){
		if(cnt>=1&&fabs(a[i])>1e-6){
			if(cnt>1)
				printf("%d %.1lf ",i,a[i]);		
			else 	printf("%d %.1lf",i,a[i]);
			cnt--;
		}	
	}	
	return 0;
} 
