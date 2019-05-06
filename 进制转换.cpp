#include<iostream>
#define MAX 100
#include<stdlib.h>
using namespace std;            //Êé54Ò³ 
typedef struct SepStack{
	int data[MAX];
	int top;
}SepStack;
SepStack *Init(){
	SepStack *s;
	s=(SepStack *)malloc(sizeof(SepStack));
	s->top=-1;
	return s;
}
void Push(SepStack *s,int x){
	s->top++;
	s->data[s->top]=x;
}
int Pop(SepStack *s){
	int x;
	x=s->data[s->top];
	s->top--;
	return x;
}
void transform(int N,int num){
	SepStack *s;
	int x;char ch;
	s=Init();
	while(num){
		Push(s,num%N);
		num=num/N;
	}
	while(s->top!=-1){
		x=Pop(s);
		if(x<10)
			cout<<x;
		else if(x>=10){
			ch='A'+(x-10);
			cout<<ch;
		}
		}
}
int main(){
	int num,N;
	cin>>num>>N;
	transform(N,num);
}
