#include<iostream>
#include<stdlib.h>
#define MaxSize 30
using namespace std;
typedef struct{
	int num[MaxSize];
	int top;
}Park;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;
typedef LNode *Linklist;
int n;
Park *InitStack(){
	Park *s;
	s=(Park*)malloc(sizeof(Park));
	if(s!=NULL){
		s->top=-1;
		return s;
	}
	else
		exit(0);
}
int IsEmpty(Park *s){
	return (s->top==-1)?1:0;
}
int Push(Park *s,int x){
	if(s->top==n-1){
		return 0;
	}
		
	else{
		s->top++;s->num[s->top]=x;
		return 1;
	}
}
int Pop(Park *s){
	int temp;
	if(!IsEmpty(s)){
		temp=s->num[s->top];
		s->top--;
		return temp;
	}
}
int GetTop(Park *s){
	if(!IsEmpty(s)){
		return s->num[s->top];
	}
}
Linklist Create(){
	Linklist L;
	L=(Linklist)malloc(sizeof(LNode));
	L->next=NULL;
	return L;
}
void ListIn(Linklist L,int x){
	Linklist p,s;
	p=L;
	while(p->next!=NULL){
		p=p->next;
	}
	s=(Linklist)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;p->next=s;
}
int ListOut(Linklist L){
	Linklist p;
	int x;
	p=L;
	if(p->next!=NULL){
		L->next=p->next;
		x=p->data;
		p->next==NULL;
		free(p);
		return x;
	}
}
int main(){
	int i,j,t,x,y,type,Q,temp;
	Park *park,*out;
	Linklist head;
	park=InitStack();
	out=InitStack();
	head=Create();
	cin>>n;
	cin>>Q;
	while(Q--){
		cin>>type;
		switch(type){
			case 1:cin>>t;
					if(!Push(park,t)){
						ListIn(head,t);
					}
					break;
			case 2:cin>>x>>t;
					i=n-x;
					while(park->top>i){
						Push(out,Pop(park));
					}
					y=t-Pop(park);
					cout<<y<<endl;
					while(!IsEmpty(out)){
						Push(park,Pop(out));
					}
					while(head->next!=NULL){
						Push(park,ListOut(head));
					}
					break;
		}
	}
	return 0;
}
