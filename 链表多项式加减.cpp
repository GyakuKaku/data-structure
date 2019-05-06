#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct PolyNode{
	int coef;
	int exp;
	struct PolyNode *next;
}PolyNode;
typedef PolyNode* Polynomial;
Polynomial CreateList(int len){
	Polynomial L;
	int i;
	Polynomial p,r;
	int x,y;
	r=L=(Polynomial)malloc(sizeof(PolyNode));
	L->next=NULL;
	for(i=0;i<len;i++){
		cin>>x>>y;
		p=(Polynomial)malloc(sizeof(PolyNode));
		p->coef=x;
		p->exp=y;
		p->next=NULL;r->next=p;
		r=p;	
	}
	return L;
}
void print_List(Polynomial L){
	Polynomial p;
	int i;
	p=L;
	if(p->next==NULL){
		cout<<"0";
	}
	else{
		p=p->next;
		cout<<p->coef<<"X"<<"^"<<p->exp;
	while(p->next!=NULL){
		p=p->next;
			if(p->coef>0)
				cout<<"+"<<p->coef<<"X"<<"^"<<p->exp;
			if(p->coef<0)
				cout<<p->coef<<"X"<<"^"<<p->exp;
	}
}
	cout<<endl;
}
void Add_Poly(Polynomial A,Polynomial B,int n){        //Êé p41 
	Polynomial S,Pa,Pb;
	int x;
	Pa=A;Pb=B;
	while(Pa->next!=NULL&&Pb->next!=NULL){
		if(Pa->next->exp==Pb->next->exp){
			S=Pa;
			Pa=Pa->next;Pb=Pb->next;
			if(n==1)
				x=Pa->coef+Pb->coef;
			if(n==2)
				x=Pa->coef-Pb->coef;
			if(x!=0){
				Pa->coef=x;
			}
			else if(x==0){
				S->next=Pa->next;
				free(Pa);
				Pa=S;
			}
		}
		else if(Pa->next->exp<Pb->next->exp){
				Pa=Pa->next;
			}
		else{
			Pb=Pb->next;
			S=(PolyNode*)malloc(sizeof(PolyNode));
			if(n==1){
				S->coef=Pb->coef;
				S->exp=Pb->exp;
			}
			if(n==2){
				S->coef=0-Pb->coef;
				S->exp=Pb->exp;
			}
			S->next=Pa->next;
			Pa->next=S;
			Pa=Pa->next;
		}
	}
	while(Pa->next!=NULL){
		Pa=Pa->next;
	}
	while(Pb->next!=NULL){
		Pb=Pb->next;
			S=(PolyNode*)malloc(sizeof(PolyNode));
			if(n==1){
				S->coef=Pb->coef;
				S->exp=Pb->exp;
			}
			if(n==2){
				S->coef=0-Pb->coef;
				S->exp=Pb->exp;
			}
			S->next=Pa->next;
			Pa->next=S;
			Pa=Pa->next;
	}
}
int main(){
	Polynomial A,B,C;
	int T,i,m,n,j,q,type,len;
	cin>>T;
	for(i=0;i<T;i++){
		cin>>m>>n;
		A=CreateList(m);
		B=CreateList(n);
		cin>>q;
		for(j=0;j<q;j++){
			cin>>type;
			switch(type){
				case 1:print_List(A);
						print_List(B);
						break;
				case 2:Add_Poly(A,B,1);
						break;
				case 3:Add_Poly(A,B,2);
						break;
			}
		}
	}
	return 0;
}
