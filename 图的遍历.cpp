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
		ArcNode *s;
		cin>>m>>n;
		s=(ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex=m;
		s->nextarc=G.vertex[n].firstarc;
		G.vertex[n].firstarc=s;
		s=(ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex=n;
		s->nextarc=G.vertex[m].firstarc;
		G.vertex[m].firstarc=s;
	}
}
int check(Graph G){
	int i;
	for(i=1;i<=G.vexnum;i++){
		if(G.visited[i]==0)
			return 0;
	}
	return 1;
}
void DFS(Graph &G,int v){
	G.visited[v]=1;
	ArcNode *w;
	if(check(G))
		cout<<v<<endl;
	else
		cout<<v<<" ";
	for(w=G.vertex[v].firstarc;w!=0;w=w->nextarc)
		if(!G.visited[w->adjvex])
			DFS(G,w->adjvex);
}
void DFSTravere(Graph G){
	int v;
	for(v=1;v<=G.vexnum;++v)
		if(!G.visited[v])
			DFS(G,v);
}
void BFS(Graph &G){
	int v,i,x;
	ArcNode *w;
	for(i=1;i<=G.vexnum;++i){
		G.visited[i]=0;
	}
	SeqQueue Q;
	Q=InitQueue();
	for(v=1;v<=G.vexnum;++v){
		if(!G.visited[v]){
			EnQ(Q,v);
			while(!Empty(Q)){
				x=DeQ(Q);
				if(G.visited[x]==0){
					G.visited[x]=1;
					cout<<x<<" ";
				}
				for(w=G.vertex[x].firstarc;w!=0;w=w->nextarc)
					if(!G.visited[w->adjvex])
						EnQ(Q,w->adjvex);
			}
		}
	}
}
int main(){
	Graph G;
	CreateAG(G);
	DFSTravere(G);
	BFS(G);
	return 0;
}
