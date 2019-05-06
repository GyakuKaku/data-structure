#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct BiTNode{
	int data;
	struct BiTNode *lc;
	struct BiTNode *rc;
}BiTNode;
typedef BiTNode *BiTree;
void insert(BiTree &T,int k){
	if(T==NULL){
		T=(BiTree)malloc(sizeof(BiTNode));
		T->data=k;
		T->lc=NULL;
		T->rc=NULL;
	}
	else if(k<=T->data)
		insert(T->lc,k);
	else if(k>T->data)
		insert(T->rc,k);
}
BiTree create(){
	BiTree T=NULL;
	int k;
	cin>>k;
	while(k!=-1){
		insert(T,k);
		cin>>k;
	}
	return T;
}
void InOrder(BiTree root){
	if(root==NULL)return;
	InOrder(root->lc);
	cout<<root->data<<" ";
	InOrder(root->rc);
}
int main(){
	BiTree root;
	root=create();
	InOrder(root);
	return 0;
}
