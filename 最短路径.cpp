#include<iostream>
#include<stdlib.h>
#define INF INT_MAX 
using namespace std;
struct minside{
	int adjvex;
	int lowcost;
}closedge[20];
typedef struct{
	int vertex[20];
	int	arcs[20][20];
	int vexnum,arcnum;
}Graph;
int min(Graph G);
void Create(Graph &G,int n,int m){
	int i,j,k,w;
	G.vexnum=n;G.arcnum=m;
	for(i=1;i<=n;i++){
		G.vertex[i]=i;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			G.arcs[i][j]=INF;
		}
	}
	for(k=0;k<m;k++){
		cin>>i>>j>>w;
		if(!(G.arcs[i][j]!=INF&&w>G.arcs[i][j]))
			G.arcs[i][j]=G.arcs[j][i]=w;
	}
}
int Prim(Graph G){
	int i,j,k,sum=0;
	closedge[1].lowcost=0;
	for(i=2;i<=G.vexnum;i++){
		closedge[i].adjvex=1;
		closedge[i].lowcost=G.arcs[1][i];
	}
	for(j=2;j<=G.vexnum;j++){
		k=min(G);
		/*cout<<closedge[k].adjvex<<" "<<k<<endl;*/
		sum+=closedge[k].lowcost;
		closedge[k].lowcost=0;
		for(i=1;i<=G.vexnum;i++){
			if(G.arcs[k][i]<closedge[i].lowcost){
				closedge[i].adjvex=k;
				closedge[i].lowcost=G.arcs[k][i];
			}
		}		
	}
	return sum;
}
int min(Graph G){
	int i,j,k=0;
	int min=0;
	for(j=1;min==0;j++){
		if(closedge[j].lowcost!=0)
			min=closedge[j].lowcost;
	}
	for(i=1;i<=G.vexnum;i++){
		if(closedge[i].lowcost!=0&&min>closedge[i].lowcost){
			min=closedge[i].lowcost;
			k=i;
		}
	}
	if(k==0){
		--j;
		k=j;
	}		
	return k;
}
int main(){
	int n,m,i,j;
	Graph G;
	cin>>n>>m;
	Create(G,n,m);
	cout<<Prim(G);
	return 0;
}
