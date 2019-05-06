#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){     //Ì«¼òµ¥ÁË 
	int m,n;
	cin>>m;
	cin>>n;
	if(m==1){
		cout<<"JYZ";
	}
	if(n%m!=0)
		cout<<"MK";
	else
		cout<<"JYZ";
	return 0;
}
