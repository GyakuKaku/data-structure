#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;
typedef  LNode *LinkList;
LinkList CreateList(int len){
	LinkList L;
	int i;
	LinkList p,r;
	int x;
	r=L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=0;i<len;i++){
		cin>>x;
		p=(LinkList)malloc(sizeof(LNode));
		p->data=x;
		p->next=NULL;r->next=p;
		r=p;	
	}
	return L;
}
void print_List(LinkList L,int len){
	LinkList p;
	int i;
	p=L->next;
	if(p==NULL)
	cout<<"-1";
	for(i=0;i<len&&p!=NULL;i++){
		if(p->next!=NULL){
			cout<<p->data<<" ";
			p=p->next;
		}
		else{
			cout<<p->data;
			p=p->next;
		}
	}
}
void ListDelete(LinkList L,int i){
	LinkList p,q;
	p=L;
	while(p->data!=i&& L->next!=NULL){
        q = p;
        p = p->next;
    }
    if(p->data==i){
        LinkList S = p->next;
        q->next = S;
        free(p);
    }
}
void Delete(LinkList L,int min,int max){
	LinkList p = L;
	LinkList q; 
	while(p->next!=NULL){
		q = p;
		p = p->next;
		if(p->data>min && p->data<max){

			ListDelete(L, p->data);
			p = L;
		}
	}
}
int main(){
	LinkList head;
	int T,i,len,q,type,min,max,m,n,j;
	cin>>T;
	for(i=0;i<T;i++){
		cin>>len;
		head=CreateList(len);
		cin>>q;
	for(i=0;i<q;i++){
			cin>>type;
			if(type==1){
				print_List(head,len);cout<<endl;;}
				else{
				cin>>min>>max;
						Delete(head,min,max);
			}
		}
	}
	return 0;
}
