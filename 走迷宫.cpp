#include<iostream>
#include<stdlib.h>
#define MaxSize 50
using namespace std;
struct PosType{
	int x,y;
};
int row,col,flag=0,k=1;
int Maze[MaxSize][MaxSize];
struct PosType Way[MaxSize];
void Try(struct PosType start){
	struct PosType next;
	struct PosType direc[4]={{1,0},{0,-1},{0,1},{-1,0}};
	for(int i=0;i<=3;i++){
		next.x=start.x+direc[i].x;
		next.y=start.y+direc[i].y;
		if(Maze[next.x][next.y]==2){
			Way[k].x=next.x-1;
			Way[k].y=next.y-1;
			flag=1;
			return;
		}
		else if(Maze[next.x][next.y]==1){
			Way[k].x=next.x-1;
			Way[k].y=next.y-1;
			k++;
			Maze[next.x][next.y]=3;
			Try(next);
			Maze[next.x][next.y]=1;
		}
	}
}
int main(){
	struct PosType start;
	int n,m,i,j;
	cin>>n>>m;
	row=n+2;col=m+2;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(i==0||j==0||i==row-1||j==col-1){
				Maze[i][j]=-1;
			}
			else{
				cin>>Maze[i][j];
				if(Maze[i][j]==0){
					start.x=i;start.y=j;
				}
			}
		}
	}
	Way[0].x=start.x-1;Way[0].y=start.y-1;
	Try(start);
	if(flag){
		cout<<"YES"<<endl;
		for(i=0;i<k;i++){
			cout<<"("<<Way[i].x<<","<<Way[i].y<<")"<<"->";
		}
		cout<<"("<<Way[i].x<<","<<Way[i].y<<")";
	}
	else{
		cout<<"NO";
	}
	
	return 0;
}
