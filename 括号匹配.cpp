#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MaxSize 100
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
	int i=0;
	char A[100];
	char *p=A;
	cin>>A;
	SeqStack *s=InitStack();
	int len=strlen(A);
	for(i=0;i<len;i++,p++){
		switch(*p){
			case '(': Push(s,*p);
					break;
			case ')': Push(s,*p);
					if(s->data[s->top-1]=='('){
						Pop(s);
						Pop(s);
					}
					break;
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
