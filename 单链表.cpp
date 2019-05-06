#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;
typedef  LNode *LinkList;
LinkList CreateList(int len){
	LinkList L,p;
	int x,i;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	if(len==0){}
	else
	for(i=0;i<len;i++){
		cin>>x;
		p=(LinkList)malloc(sizeof(LNode));
		p->data=x;
		p->next=L->next;L->next=p;	
	}
	return L;
}
void Createpoint(LinkList L,int x,int y){
	LinkList p,S;
	p=L;
	while(p->next!=NULL){
		if(p->next->data==y){
			S=(LinkList)malloc(sizeof(LNode));
			S->data=x;
			S->next=p->next;p->next=S;
			p=p->next;
		}
		p=p->next;
	}
}
void reverse(LinkList L){
	if(L->next!=NULL&&L->next->next!=NULL){
		LinkList p,S;
		p=L->next;
		S=p->next;
		p->next=NULL;
		L->next=p;
		p=S;
		while(S->next!=NULL){
			S=p->next;
			p->next=L->next;
			L->next=p;
			p=S;
		}
		S->next=L->next;
		L->next=S;
	}
	}
void Deletepoint(LinkList L){
	LinkList p,S,q,pp;
	int c=0;
	p=L;
	while(p->next!=NULL){
		c=0;
		q=p;
		p=p->next;
		S=p;
		while(S->next!=NULL){
			pp=S;
			S=S->next;
			if(S->data==p->data){
					pp->next=S->next;
					free(S);
					S=pp;
					c=1;
			}
		}
		if(c==1){
			q->next=p->next;
			free(p);
			p=q;
		}
	}
}
void printlist(LinkList L){
	LinkList p;
	p=L;
	if(p->next==NULL)
		cout<<"-1";
	else	
		while(p->next!=NULL){
			p=p->next;
			if(p->next!=NULL){
				cout<<p->data<<" ";
			}
			else{
				cout<<p->data;
			}
		}
	cout<<endl;
}
int main(){
	int T,i,j,n,q,type,x,y;
	LinkList head;
	cin>>T;
	for(i=0;i<T;i++){
		cin>>n;
		head=CreateList(n);
		cin>>q;
		for(j=0;j<q;j++){
			cin>>type;
			switch(type){
				case 1:cin>>x>>y;
						Createpoint(head,x,y);
						break;
				case 2:reverse(head);
						break;
				case 3:Deletepoint(head);
						break;
				case 4:printlist(head);
						break;
			}
		}
	}
	return 0;
}


