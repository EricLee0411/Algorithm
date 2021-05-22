#include<iostream>
using namespace std;
int even(int j){
	int u=j%2;
	if(u==0) return j;
	else return 0;
}
int main(){
	int n;
	int k=1;
	cin>>n;
	while(n!=0){
		int s,t;
		cin>>s>>t;
		int sum=0;
		for(int i=s;i<=t;i++){
			sum+=even(i);
		}
		cout<<"Case "<<k<<": "<<sum<<endl;
		n--;
		k++; 
	}
}
