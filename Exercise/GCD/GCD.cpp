#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n!=0){
		int s,t;
		cin>>s>>t;
		if(s>t){
			int temp=s;
			s=t;
			t=temp;
		}
		int w;
		for(int i=1;i<=s;i++){
			int u=s%i;
			int v=t%i;
			if(u==0&&v==0) w=i;
		}
		cout<<w<<endl; 
		n--;
	}
}
