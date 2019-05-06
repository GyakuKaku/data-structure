#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LNode{
	int id;
	int sec;
	struct LNode *next;
}LNode;
typedef LNode* Polynomial;
Polynomial head=NULL,rear=NULL;
void Create_List(int n){
	int i;Polynomial p;
	head=(Polynomial)malloc(sizeof(LNode));
	head->id=1;
	cin>>head->sec;
	rear=head;
	for(i=2;i<=n;i++){
		p=(Polynomial)malloc(sizeof(LNode));
		p->id=i;
		p->next=NULL;
		cin>>(p->sec);
		rear->next=p;
		rear=p;
	}
	rear->next=head;
}
void Column(int n,int m){
	int k=n;int j,s,i=0;
	Polynomial p;
	for(j=0;j<k;){
		s=1;
		while(s<m){
			rear=head;
			head=head->next;
			s++;
		}
		if(i==0){
			cout<<head->id;
		}	
		else
		cout<<" "<<head->id;
		m=head->sec;
		j++;
		p=head;
		head=p->next;
		rear->next=head;
		free(p);
		i++;
	}
	cout<<endl;
}
int main(){
	Polynomial head,rear;
	int T,i,m,n;
	cin>>T;
	for(i=0;i<T;i++){
		cin>>n>>m;
		Create_List(n);
		Column(n,m);
	}
	return 0; 
}
