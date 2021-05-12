#include<iostream>
using namespace std;
int oddprime(int j){
	int u=j%2;
	int r=j-1;
	int m=j%r;
	while(m != 0){
		r--;
		m=j%r;
	}
	if((m==0&&r==1)||u==0) return 0;
	else return j;
}
int main(){
	int n;
	cin>>n;
	while(n!=0){
		int s,t;
		cin>>s>>t;
		int sum=0;
		for(int i=s;i<=t;i++){
			sum+=oddprime(i);
		}
		cout<<sum<<endl;
		n--;
	}
}
