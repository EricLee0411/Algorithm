#include<iostream>
using namespace std;
int checklosepage(int i){
	int page=1;
	int checkpagesum=0;
	while(i>=checkpagesum){
		checkpagesum+=page;
//		cout<<checkpagesum<<" "<< page<<endl;
		page++;
	}
	return checkpagesum-i;
}
int allpage(int i){
	int page=1;
	int checkpagesum=0;
	while(i>=checkpagesum){
		checkpagesum+=page;
//		cout<<checkpagesum<<" "<< page<<endl;
		page++;
	}
	return page-1;
}
int main(){
	int n;
	cin>>n;
	while(n!=0){
		int pagesum;
		cin>>pagesum;
		cout<<allpage(pagesum)<<" "<<checklosepage(pagesum)<<endl;
		n--;
	}
}
