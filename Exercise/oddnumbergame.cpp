#include<iostream>
#include<vector>
using namespace std;
long long oddnumbergame(int n){
	int count=1;
	long long goal=1;
	while(count!=n){
		count+=2;
		goal+=2*count;
	}
	return goal*(goal-2)*(goal-4);
}
int main(){
	int num;
	cin>>num;
	while(num!=0){
		int number;
		cin>>number;
		if(1<number&&number<1000000000) cout<<oddnumbergame(number)<<endl;
		num--;
	}
}
//double oddnumbergame(int n){
//	int count=1;
//	double goal=1;
//	while(count!=n){
//		count+=2;
//		goal+=2*count;
//	}
//	return goal*(goal-2)*(goal-4);
//}
//int main(){
//	vector<int> N;
//	int num;
//	cin>>num;
//	while(num!=0){
//		int number;
//		cin>>number;
//		if(1<number&&number<1000000000)N.push_back(number);
//		num--;
//	}
//	for(int i=0;i<N.size();i++) cout<<oddnumbergame(N[i])<<endl;
//}
