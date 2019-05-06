#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct{
	int base[30];
	int front,rear;
}SeqQueue;
SeqQueue InitQueue(){
	SeqQueue Q;
	Q.front=0;
	Q.rear=0;
	return Q;
}
int Empty(SeqQueue Q){
	return(Q.front==Q.rear)?1:0;
}
void EnQ(SeqQueue &Q,int x){
	Q.base[Q.rear]=x;
	Q.rear=(Q.rear+1)%30;
}
int DeQ(SeqQueue &Q){ 
	int x;
	if(Q.front==Q.rear){
		return 0;
	}
	else{
		x=Q.base[Q.front];
		Q.front=(Q.front+1)%30;
	}
	return x;
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
		if(G.vertex[m].firstarc!=NULL){
			temp=G.vertex[m].firstarc;
		while(temp->nextarc!=NULL)
			temp=temp->nextarc;
		s=(ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex=n;
		s->nextarc=temp->nextarc;
		temp->nextarc=s;
		}
		else{
			s=(ArcNode *)malloc(sizeof(ArcNode));
			s->adjvex=n;
			s->nextarc=G.vertex[m].firstarc;
			G.vertex[m].firstarc=s;
		}
	}
}
void FindInDegree(Graph G,int indegree[]){
	int i;
	ArcNode *p;
	for(i=1;i<=G.vexnum;i++)
		indegree[i]=0;
	for(i=1;i<=G.vexnum;i++){
		if(G.vertex[i].firstarc!=NULL){
			p=G.vertex[i].firstarc;
			while(p){
				indegree[p->adjvex]++;
				p=p->nextarc;
			}
		}
	}
}
void TS(Graph &G){
	int i,k,count,indegree[30];
	ArcNode *p;
	SeqQueue s;
	s=InitQueue();
	FindInDegree(G,indegree);
	for(i=1;i<=G.vexnum;++i){
		if(indegree[i]==0)
		EnQ(s,i);
	}
	count=0;
	while(!Empty(s)){
		i=DeQ(s);
		cout<<i<<" ";
		++count;
		for(p=G.vertex[i].firstarc;p;p=p->nextarc){
			k=p->adjvex;
			if(!(--indegree[k])){
				EnQ(s,k);
			}
		}
	}
}
int main(){
		int i,k,count,indegree[30];
	Graph G;
	CreateAG(G);
	TS(G);
	return 0;
}
