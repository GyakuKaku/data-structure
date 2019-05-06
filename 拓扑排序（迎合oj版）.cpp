#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct{
	int top;
	int data[20];
}Stack;
Stack *InitS(){
	Stack *s;
	s=(Stack *)malloc(sizeof(Stack));
	s->top=0;
	return s;
}
int Empty(Stack *s){
	return(s->top==0)?1:0;
}
int Gettop(Stack *s){
	return s->data[s->top];
}
void Push(Stack *s,int x){
	if(s->top==20){
		cout<<"NO";
	}
	s->top++;
	s->data[s->top]=x;
}
int Pop(Stack *s){
	int t=s->data[s->top];
	if(Empty(s)){
		cout<<"NO";
	}
	else{
		s->top--;		
	}
	return t;
}
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
	int data;
	ArcNode *firstarc;
}VNode,AdjList[20];
typedef struct{
	AdjList vertex;
	int vexnum,arcnum;
	int visited[20];
}Graph;
void CreateAG(Graph &G){
	int i,n,m;
	cin>>n>>m;
	G.arcnum=m;
	G.vexnum=n;
	for(i=1;i<=n;++i){
		G.vertex[i].data=i;G.vertex[i].firstarc=NULL;
		G.visited[i]=0;
	}
	for(i=1;i<=G.arcnum;++i){
		ArcNode *s,*temp;
		cin>>m>>n;
		s=(ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex=n;
		if(G.vertex[m].firstarc==NULL||n>G.vertex[m].firstarc->adjvex){
			s->nextarc=G.vertex[m].firstarc;
			G.vertex[m].firstarc=s;
		}
		else{			
			temp=G.vertex[m].firstarc;
			while(temp->nextarc!=NULL&&temp->adjvex<n){			
					temp=temp->nextarc;
			}
			s->nextarc=temp->nextarc;
			temp->nextarc=s;
		}
	}
}
void FindInDegree(Graph G,int indegree[]){
	int i;
	ArcNode *p;
	for(i=1;i<=G.vexnum;i++)
		indegree[i]=0;
	for(i=1;i<=G.vexnum;i++){
		p=G.vertex[i].firstarc;
		while(p){
			indegree[p->adjvex]++;
			p=p->nextarc;
		}
	}
}
void TS(Graph &G){
	int i,k,j=100,temp=100,flag=0,indegree[30];
	ArcNode *p;
	Stack *s;
	s=InitS();
	FindInDegree(G,indegree);
	for(i=G.vexnum;i>=1;--i){
		if(indegree[i]==0)
		Push(s,i);
	}
	while(!Empty(s)){
		i=Pop(s);
		if((!flag)||i!=temp)
		cout<<i<<" ";
		if(i==temp)
			flag++;
		if(!Empty(s)){
			j=Gettop(s);
		}
		for(p=G.vertex[i].firstarc;p;p=p->nextarc){
			k=p->adjvex;
			if(!(--indegree[k])){
				Push(s,k);
			}
			if(j<k){
				Push(s,j);
				temp=j;
				if(indegree[j]!=0)
					indegree[j]--;
			}				
		}
	}
}
int main(){
	Graph G;
	CreateAG(G);
	TS(G);
	return 0;
}
