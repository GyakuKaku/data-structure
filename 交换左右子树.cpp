#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild; 
}BiTNode;
typedef BiTNode *BiTree;
BiTree temp;
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
void InOrder(BiTree root){
	if(root==NULL) return;
	InOrder(root->lchild);
	cout<<root->data;
	InOrder(root->rchild);
}
void Change(BiTree root){
	if(root==NULL) return;
	Change(root->lchild);
	Change(root->rchild);
	temp=root->lchild;
	root->lchild=root->rchild;
	root->rchild=temp;
}
int main(){
	BiTree root;
	Create(root);
	Change(root);
	InOrder(root);
}
