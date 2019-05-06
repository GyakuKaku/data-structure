#include<iostream>
#include<stdlib.h>
using namespace std;
int Divisor(int m,int n){
	if(n==0)
		return m;
	else
		return Divisor(n,m%n);
}
int main(){
	int m, n;
	cin>>m>>n;
	cout<<Divisor(m,n);
}
