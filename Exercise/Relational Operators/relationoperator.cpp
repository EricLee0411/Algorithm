#include <iostream>
using namespace std;
//void ReOpe(int f,int s){
//	if(f==s) cout<<'='<<endl;
//	else if(f<s) cout<<'<'<<endl;
//	else cout<<'>'<<endl;
//}
int ReOpe(int,int);
int main() {
	int first,second;
	cin>>first;
	while(first!=0){
		cin>>second;
		if(ReOpe(first,second)==0) 
			cout<<"="<<endl;
		if(ReOpe(first,second)==1) 
			cout<<">"<<endl;
		if(ReOpe(first,second)==-1)  
			cout<<"<"<<endl;
		cin>>first;
	}
}
int ReOpe(int f,int s){
	if(f==s) 
		return 0;
	if(f<s) 
		return -1;
	if(f>s) 
		return 1;
}
