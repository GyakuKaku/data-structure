#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxNode 50
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild; 
}BiTNode;
typedef BiTNode *BiTree;
void Create(BiTree &root){
	char x;
	cin>>x;
	if(x=='#') root=NULL;
	else{
		root=(BiTree)malloc(sizeof(BiTNode));
		root->data=x;
		Create(root->lchild);
		Create(root->rchild);
	}
}
void PreOrder(BiTree root){
	if(root==NULL) return;
	cout<<root->data;
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
void InOrder(BiTree root){
	BiTree p,stack[MaxNode];
	int top=0;
	if(root==NULL) return;
	p=root;
	while(!(p==NULL&&top==0)){
		while(p!=NULL){
			
			if(top<MaxNode-1){
				stack[top]=p;
				top++;
			}
			else{
				return;
			}
			p=p->lchild;
		}
		if(top<0)
		return;
		else{
			top--;
			p=stack[top];
			cout<<p->data;
			p=p->rchild;
		}
	}
}
void postOrder(BiTree root){
	if(root==NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	cout<<root->data;
}
int f(BiTree root,int x){
	if(root==NULL)return 0;
	else if(root->data==x) return (1+f(root->lchild,x)+f(root->rchild,x));
	else return f(root->lchild,x)+f(root->rchild,x);
}
int main(){
	BiTree root;
	Create(root);
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	postOrder(root);
	cout<<endl;
	cout<<f(root,3);
	return 0;
}
