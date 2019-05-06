#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int Convert(char A[],int n){
	if(n==0)
		cout<<(int)(A[n]-'0');
	else{
		Convert(A,n-1);
		cout<<(int)(A[n]-'0');		
	}
}
int main(){
	int n;
	char A[100];
	cin>>A;
	n=strlen(A);
	Convert(A,n-1);
}
