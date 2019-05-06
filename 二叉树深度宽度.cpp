#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild; 
}BiTNode;
typedef BiTNode *BiTree;
typedef struct LNode{
	int lv;
	struct LNode *next;
}LNode;
typedef LNode *List;
List l;
int level=0;
List Search_last(List L,int x){
	List p=L;
	while(p->next!=NULL&&p->lv!=x)
		p=p->next;	
	while(p->next!=NULL&&p->next->lv==x)
		p=p->next;
	while(p->next!=NULL&&p->next->lv==x+1)
		p=p->next;	
	return p;
}
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
void Level(BiTree root,List head){
	if(root==NULL) return;
	List temp;
	temp=(List)malloc(sizeof(LNode));
	temp->lv=level;
	l=Search_last(head,level-1);
	temp->next=l->next;
	l->next=temp;
	level++;
	Level(root->lchild,head);
	level--;
	level++;
	Level(root->rchild,head);
	level--;
	
}
int HW(List head){
	level=0;
	int width=0,width2=0;
	List p=head;
	while(p->next!=NULL){
		if(p->next->lv==p->lv)
			width++;
		else if(p->next->lv!=p->lv){
			width2=width;
			width=1; 
			
		}
			
		p=p->next;
		if(level<p->lv)
			level=p->lv;
	}
	return width2;
}
int main(){
	List head;
	int width;
	head=(List)malloc(sizeof(LNode));
	head->lv=-1;
	head->next=NULL;
	BiTree root;
	Create(root);
	Level(root,head);
	width=HW(head);
	cout<<level+1<<" "<<width;
}
