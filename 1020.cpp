#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;
int postorder[40]={0},inorder[40]={0};
struct Node{
	int data;
	struct Node *right,*left;
};
Node *createTree(int postleft,int postright,int inleft,int inright){//这里返回void为什么不行？ 
	if(postleft>postright)	return NULL;
	Node* tree=new Node;
	tree->data=postorder[postright];
	int pos;
	for(pos=inleft;pos<=inright;pos++)
		if(inorder[pos]==tree->data)	break;
	tree->left=createTree(postleft,postleft+pos-inleft-1,inleft,pos-1);
	tree->right=createTree(postleft+pos-inleft,postright-1,pos+1,inright);
	return tree;
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
    	cin>>inorder[i];
    Node *root=NULL;
    root=createTree(1,N,1,N);
    queue<Node*> q;
    q.push(root);
    int firstOutputFlag=1;
    while(!q.empty()){	
    	if(firstOutputFlag){
    		cout<<q.front()->data;
    		firstOutputFlag=0;
		}
    	else  cout<<" "<<q.front()->data;
    	if(q.front()->left)
    		q.push(q.front()->left);
    	if(q.front()->right)
    		q.push(q.front()->right);
    	q.pop();
	}
    return 0;
}
