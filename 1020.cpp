#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;
int postorder[40]={0},inorder[40]={0};
struct Node{
	int data;
	struct Node *right=NULL,*left=NULL;
};
void createTree(Node*& tree,int postleft,int postright,int inleft,int inright){//建树函数返回void,BFS的队列元素类型是Node
	if(postleft>postright)	return;
	tree=new Node;
	tree->data=postorder[postright];
	int pos;
	for(pos=inleft;pos<=inright;pos++)
		if(inorder[pos]==tree->data)	break;
	createTree(tree->left,postleft,postleft+pos-inleft-1,inleft,pos-1);
	createTree(tree->right,postleft+pos-inleft,postright-1,pos+1,inright);
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
    createTree(root,1,N,1,N);
    queue<Node> q;
    q.push(*root);
    int firstOutputFlag=1;
    while(!q.empty()){	
    	if(firstOutputFlag){
    		cout<<q.front().data;
    		firstOutputFlag=0;
		}
    	else  cout<<" "<<q.front().data;
    	if(q.front().left)
    		q.push(*(q.front().left));
    	if(q.front().right)
    		q.push(*(q.front().right));
    	q.pop();
	}
    return 0;
}
