#include<iostream>
#include<stdlib.h>
using namespace std;
int Max(int *p,int n){
	if(n<=0)
	 return *p;
	else{
		if(*(p+n)>Max(p,n-1))
			return *(p+n);
		else
			return Max(p,n-1);
	}
}
int Add(int *p,int n){
	if(n==0)
	 return *p;
	else{
		return *(p+n)+Add(p,n-1);
	}
}
int main(){
	int *p,n,i;
	cin>>n;
	p=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		cin>>*(p+i);
	cout<<Max(p,n-1)<<endl;
	cout<<Add(p,n-1)<<endl;
	cout<<Add(p,n-1)/n;
	return 0;
}
