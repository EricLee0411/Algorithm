#include<iostream>
using namespace std;
int smoking(int s,int t){
	int sum=0;
	sum+=t;
	int quotion=t/s;
	int remainder=t%s;
	while(quotion!=0){
		sum+=quotion;
		quotion+=remainder;
		remainder=quotion%s;
		quotion/=s;
	}
	return sum;
} 
int main(){
	int number;
	cin>>number;
	while(number!=0){
		int num1,num2;
		cin>>num1>>num2;
//		vector<int> smoke;
//	for(int i=0;i<number;i++){
//		cin>>num1>>num2;
//		smoke.push_back(num1);
//		smoke.push_back(num2);
//	}	
//		for(int i=0;i<number;i++){
		if(num1>1) cout<<smoking(num1,num2/*smoke[2*i],smoke[2*i+1]*/)<<endl;
//		}
		number--;
	}
}
