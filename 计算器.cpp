#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
//Êé58Ò³ 
typedef struct node{
	int data;
	struct node *next;
}LinkStack;
int priority[7][7]={3,3,1,1,1,3,3,
					3,3,1,1,1,3,3,
					3,3,3,3,1,3,3,
					3,3,3,3,1,3,3,
					1,1,1,1,1,2,2,
					3,3,3,3,0,3,3,
					1,1,1,1,1,0,2};
int IsEmpty(LinkStack *top){
	return top?0:1;
}
LinkStack *Push(LinkStack *top,int x){
	LinkStack *p;
	p=(LinkStack *)malloc(sizeof(LinkStack));
	if(p){
		p->data=x;
		p->next=top;
		top=p;
	}
	else{
		exit(0);
	}
	return top;
}
LinkStack *Pop(LinkStack *top,int *x){
	LinkStack *s;
	if(IsEmpty(top)){
		return NULL;
	}
	else{
		s=top;
		*x=top->data;
		top=top->next;
		free(s);
		return top;
	}
}
int GetTop(LinkStack *top){
	if(IsEmpty(top)){
		cout<<"¿ÕÕ» ";
		return 0;
	}
	else
		return top->data;
}
int sub(int c){
	switch(c){
		case '+':return 0;
		case '-':return 1;
		case '*':return 2;
		case '/':return 3;
		case '(':return 4;
		case ')':return 5;
		case '#':return 6;
	}
}
int main(){
	int x1,x2,i,j,k,op,temp;
	char ch;
	LinkStack *OPTR=NULL;
	LinkStack *OPND=NULL;
	OPTR=Push(OPTR,'#');
	ch=getchar();
	while(!(ch=='#'&&GetTop(OPTR)=='#')){
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='#'){
			i=sub(GetTop(OPTR));
			j=sub(ch);
			if(priority[i][j]==3){
				OPTR=Pop(OPTR,&op);
				OPND=Pop(OPND,&x2);
				OPND=Pop(OPND,&x1);
				switch(op){
					case '+':
							OPND=Push(OPND,x1+x2);break;
					case '-':
							OPND=Push(OPND,x1-x2);break;
					case '*':
							OPND=Push(OPND,x1*x2);break;
					case '/':
							OPND=Push(OPND,x1/x2);
				}
				continue;
			}
			if(priority[i][j]==1)
				OPTR=Push(OPTR,ch);
			if(priority[i][j]==2)
				OPTR=Pop(OPTR,&temp);
		}
		else OPND=Push(OPND,ch-48);
		ch=getchar();
		if(ch=='\n'){
			ch='#';
		}
	}
	cout<<GetTop(OPND);
	return 0;
}
