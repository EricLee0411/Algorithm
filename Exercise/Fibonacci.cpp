#include<iostream>
using namespace std;
int Fib(int n,int i,int j,int k){   
    if(n>2){    
         k=i+j;    
         i=j;    
         j=k;    
         Fib(n-1,i,j,k);    
	}
	else if(n==2){
		return k;
	}
}
int main(){
	int m;
	cin>>m;
	while(m!=0){
		int num;
		cin>>num;
		int f1=1,f2=1,f3=0;
		if(num==1) cout<<1<<endl; 
		else if(num==2) cout<<1<<endl; 
		else cout<<Fib(num,f1,f2,f3)<<endl; 
		m--;
	}
}
