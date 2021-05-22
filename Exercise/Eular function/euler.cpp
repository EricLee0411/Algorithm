#include<iostream>
using namespace std;
int coprime(int a,int b){
	int gcd;
	for(int i=1;i<=a;i++){
		int u=a%i;
		int v=b%i;
		if(u==0&&v==0) gcd=i;
	}
	return gcd;
} 
int Euler(int x){
	int count=1;
	for(int i=2;i<x;i++){
		if (coprime(i,x)==1) count++;
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	while(n!=0){
		int num;
		cin>>num;
		cout<<Euler(num)<<endl;
		n--;
	}
}
