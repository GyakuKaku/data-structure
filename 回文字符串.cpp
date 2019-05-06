#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MaxSize 200
using namespace std;
typedef struct{
	char data[MaxSize];
	int top;
}SeqStack;
SeqStack *InitStack(){
	SeqStack *s;
	s=(SeqStack *)malloc(sizeof(SeqStack));
	if(s!=NULL){
		s->top=-1;
		return s;
	}
	else{
		exit(0);
	}
}
int IsEmpty(SeqStack *s){
	return (s->top==-1)?1:0;
}
void Push(SeqStack *s,char x){
	if(s->top==MaxSize){
		exit(1);
	}
	else{
		s->top++;
		s->data[s->top]=x;
	}
}
void Pop(SeqStack *s){
	char ch;
	if(IsEmpty(s)){
		exit(2);
	}
	else{
		s->top--;
	}
}
char GetTop(SeqStack *s){
	if(IsEmpty(s)){
		exit(3);
	}
	else
		return s->data[s->top];
}
int main(){
	int i=0,flag=0;
	char A[200];
	char *p=A;
	cin>>A;
	SeqStack *s=InitStack();
	int len=strlen(A);
	int l;
	if(len%2==0){
		l=len/2;
	}
	else{
		l=(len-1)/2;
		flag=1;
	}
	for(i=0;i<l;i++,p++){
		Push(s,*p);
	}
	if(flag==1){
		p++;
	}
	for(i=0;i<l;i++,p++){
		Push(s,*p);
		if(s->data[s->top-1]==s->data[s->top]){
			Pop(s);
			Pop(s);
		}
	}
	if(IsEmpty(s)){
		cout<<"Yes";
	}
	else{
		cout<<"NO";
	}
	return 0;
}
