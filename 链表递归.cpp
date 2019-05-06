#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;
typedef LNode *LinkList;
LinkList Create(){
	LinkList L,p,r;
	int x;
	r=L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	cin>>x;
	while(x!=-1){
		p=(LinkList)malloc(sizeof(LNode));
		p->data=x;
		p->next=NULL;
		r->next=p;
		r=p;
		cin>>x;
	}
	return L;
}
int Max(LinkList L){
	LinkList p=L->next;
	if(p->next==NULL){
		return p->data;
	}
	else{
		if(p->data<Max(p))
			return Max(p);
		else
			return p->data;
	}
}
int num(LinkList L){
	LinkList p=L->next;
	if(p->next==NULL){
		return 1;
	}
	else{
		return num(p)+1;
	}
}
int Add(LinkList L){
	LinkList p=L->next;
	if(p->next==NULL){
		return p->data;
	}
	else{
		return p->data+Add(p);
	}
}
int main(){
	LinkList head;
	head=Create();
	cout<<Max(head)<<endl;
	cout<<num(head)<<endl;
	cout<<Add(head)/num(head);
}
