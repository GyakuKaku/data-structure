#include<iostream>
#include<stdlib.h>
#define MaxSize 100
using namespace std;
typedef struct SqList{
	int data[MaxSize];
	int length;
}SqList;
SqList *init_SqList(int len){
	SqList *L;int x,i;
	L=(SqList*)malloc(sizeof(SqList));
	if(!L)
		exit(1);
	L->length=len;
	for(i=0;i<len;i++){
		cin>>x;
		L->data[i]=x;
	}
	return L;	
}
void Print_List(SqList *L){
	int i=0;
	if(L->length==0){
		cout<<"-1"<<endl;
	}
	else{
		for(i=0;i<L->length-1;i++){
		cout<<L->data[i]<<" ";
	}
	cout<<L->data[i];
	cout<<endl;
	}
}
void Deletepoint(SqList* L,int x){
	int i=0,j;
	while(L->data[i]!=x&&i<L->length-1){
		i++;
	}
	if(L->data[i]==x){
		for(;i<L->length-1;i++){
			L->data[i]=L->data[i+1];
		}
		L->length=L->length-1;
	}
	else{
		cout<<"-1"<<endl;
	}
}
int main(){
	SqList *L;
	int T,type,q,n,x,i,j;
	cin>>T;
	for(i=0;i<T;i++){
		cin>>n;
		L=init_SqList(n);
		cin>>q;
		for(j=0;j<q;j++){
			cin>>type;
			if(type==0){
				Print_List(L);
			}
			else{
				cin>>x;
				Deletepoint(L,x);
			}
		}
	}
	return 0;
}

