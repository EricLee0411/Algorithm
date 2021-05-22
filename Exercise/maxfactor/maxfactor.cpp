#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int r=n-1;
	int m=n%r;
	while(m!=0){
		r--;
		m=n%r;
	}
	cout<<r<<endl;
}
