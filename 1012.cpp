#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;
struct student{
	string id;
	int C;
	int M;
	int E;
	int A; 
	int c_ranking;
	int m_ranking;
	int e_ranking;
	int a_ranking;
};
int cmp_c(student &a,student &b){
	return a.C>b.C;
}
int cmp_m(student &a,student &b){
	return a.M>b.M;
}
int cmp_e(student &a,student &b){
	return a.E>b.E;
}
int cmp_a(student &a,student &b){
	return a.A>b.A;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int studentNum,checkNum;
	cin>>studentNum>>checkNum;
	student s[studentNum];
	for(int i=0;i<studentNum;i++){
		cin>>s[i].id>>s[i].C>>s[i].M>>s[i].E;
		s[i].A=(s[i].C+s[i].M+s[i].E)/3;
	}
	//做处理
	sort(s,s+studentNum,cmp_a);
	s[0].a_ranking=1;
	for(int k=1;k<studentNum;k++){
		if(s[k].A==s[k-1].A)	s[k].a_ranking=s[k-1].a_ranking;
		else s[k].a_ranking=k+1;
	}
/*	for(int i=0;i<studentNum;i++){
		cout<<"A:"<<endl;
		cout<<s[i].id<<" "<<s[i].C<<" "<<s[i].M<<" "<<s[i].E<<" "<<s[i].A<<endl;
		cout<<s[i].a_ranking['A']<<endl;
    }
*/   
	sort(s,s+studentNum,cmp_c);
	s[0].c_ranking=1;
	for(int k=1;k<studentNum;k++){
		if(s[k].C==s[k-1].C)	s[k].c_ranking=s[k-1].c_ranking;
		else s[k].c_ranking=k+1;
	}

	sort(s,s+studentNum,cmp_m);
	s[0].m_ranking=1;
	for(int k=1;k<studentNum;k++){
		if(s[k].M==s[k-1].M)	s[k].m_ranking=s[k-1].m_ranking;
		else s[k].m_ranking=k+1;
	}
	sort(s,s+studentNum,cmp_e);
	s[0].e_ranking=1;
	for(int k=1;k<studentNum;k++){
		if(s[k].E==s[k-1].E)	s[k].e_ranking=s[k-1].e_ranking;
		else s[k].e_ranking=k+1;
	}
	string s_id;
	int bestRanking,i;
	char bestMajor;
	for(int j=0;j<checkNum;j++){
		cin>>s_id;
		for(i=0;i<studentNum;i++){
			if(s[i].id==s_id)
			{	//找到成绩最好的那一项，若相同则按优先级 A > C > M > E.输出最高的那一项  
				bestRanking=s[i].e_ranking;
				bestMajor='E';
				if(s[i].m_ranking<=bestRanking){
					bestRanking=s[i].m_ranking;
					bestMajor='M';
				}
				if(s[i].c_ranking<=bestRanking){
					bestRanking=s[i].c_ranking;
					bestMajor='C';
				}	
				if(s[i].a_ranking<=bestRanking){
					bestRanking=s[i].a_ranking;
					bestMajor='A';
				}	
				break;
			}
		}
		if(i>=studentNum)	cout<<"N/A"<<endl;
		else cout<<bestRanking<<" "<<bestMajor<<endl;
	} 
	return 0;
}
/*
Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
*/ 

