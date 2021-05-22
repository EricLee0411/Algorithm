#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==1) cout<<"Y"<<endl;
	int r=n-1;
	int m=n%r;
	while(m!=0){
		r--;
		m=n%r;
	}
	if(m==0&&r==1) cout<<"Y"<<endl;
	else cout<<"N"<<endl;
}
