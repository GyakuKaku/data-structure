#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int A[n+1];
	int i=0;
	for(i=0;i<n;i++)
		cin>>A[i+1];
	A[0]=m;
	i=n+1;
	while(A[i]!=m)
		i--;
	if(i!=0)
		cout<<i;
	else 
		cout<<"-1";
	return 0;
}
