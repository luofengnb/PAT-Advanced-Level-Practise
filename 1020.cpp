#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;
int postorder[40]={0},inorder[40]={0};
struct Node{
	int data;
	struct Node *right=NULL,*left=NULL;
};
void createTree(Node* &p,int postleft,int postright,int inleft,int inright){
	if(postleft>postright&&inleft>inright)	return;
	Node t;
	t.data=postorder[postright];
	cout<<"t.data="<<t.data<<endl;
	int pos;
	for(pos=inleft;pos<=inright;pos++)
		if(inorder[pos]==t.data)	break;
	createTree(t.left,postleft,pos-1,inleft,pos-1);
	createTree(t.right,pos,postright-1,pos+1,inright);
}
int main(){_
	#ifdef INPUT
	freopen("data.in","r",stdin);
	#endif
    int N;
    cin>>N;
    for(int i=1;i<N+1;i++)
    	cin>>postorder[i];
    for(int i=1;i<N+1;i++)
    	cout<<"postorder="<<postorder[i]<<endl;
    for(int i=1;i<N+1;i++)
    	cin>>inorder[i];
    Node *root;
    createTree(root,1,N,1,N);
    queue<Node> q;
    q.push(*root);
    int firstOutputFlag=1;
    while(!q.empty()){
    	if(firstOutputFlag){
    		cout<<q.front().data;
    		firstOutputFlag=0;
		}
    	else cout<<" "<<q.front().data;
    	if(q.front().left)
    		q.push(*(q.front().left));
    	if(q.front().right)
    		q.push(*(q.front().right));
    	q.pop();
	}
    return 0;
}
