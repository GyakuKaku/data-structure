#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct HNode{
	char *name;
	struct HNode *next;
}HNode;
typedef HNode *HName;
HName *CreatHT(){
	HName *HT;
	int i=0;
	HT=(HName *)malloc(26*sizeof(HName));
	while(i<26){
		HT[i]=NULL;
		i++;
	}
	return HT;
}
void Insert(HName *HT){
	char *name;
	name=(char *)malloc(sizeof(char)*50);
	gets(name);
	char h=name[0];
	int i=h%97;
	HName n=(HName)malloc(sizeof(HNode));
	n->name=name;
	n->next=NULL;
	if(HT[i]==NULL){
		HT[i]=n;
	}
	else{
		n->next=HT[i];
		HT[i]=n;
	}
}
void Search(HName *HT){
	char *name;
	name=(char *)malloc(sizeof(char)*50);
	gets(name);
	int i,lenHT,k,m,p;
	int len=strlen(name);
	for(i=0;i<26;i++){		
		HName n=HT[i];
		if(HT[i]!=NULL){
			while(n!=NULL){
				m=0;p=0;
				lenHT=strlen(n->name);
				k=lenHT-len;
				switch(k){
					case 1:{
						while(n->name[m]==name[p]&&m<lenHT){
							m++;p++;
						}
						if(m<lenHT) m++;
						while(n->name[m]==name[p]&&m<lenHT){
							m++;p++;
						}
						if(m==lenHT){
							cout<<"1"<<endl;
							return;
						}
						break;
					}
					case 0:{
						if(!strcmp(n->name,name)){
						cout<<"1"<<endl;
						return;
						}						
						break;
					}
					case -1:{
						while(n->name[m]==name[p]&&p<len){
							m++;p++;
						}
						if(p<len) p++;
						while(n->name[m]==name[p]&&p<len){
							m++;p++;
						}
						if(p==len){
							cout<<"1"<<endl;
							return;
						}
						break;
					}
				}
				n=n->next;
			}	
		}		
	}
	cout<<"0"<<endl;
}
int main(){
	HName *HT;
	int n,q,i;
	cin>>n>>q;
	HT=CreatHT();
	for(i=0;i<n+1;i++)
		Insert(HT);
	for(i=0;i<q;i++)
		Search(HT);
	return 0;
}
