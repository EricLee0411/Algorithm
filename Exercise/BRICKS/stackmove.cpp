#include<iostream>
#include<vector>
using namespace std;
int movement(vector<int> s,int size){
	int sum=0;
	for(int i=0;i<size;i++) sum+=s[i];
	int avg=sum/size;
	int time=0;
	for(int i=0;i<size;i++){
		int sub=s[i]-avg;
		if(sub>0) time+=sub;
		else continue;
	} 
	return time;
	
} 
int main(){
	int number;
	cin>>number;
	while(number!=0){
		int num;
		cin>>num;
		vector<int> stack;
		for(int i=0;i<num;i++){
			int n;
			cin>>n;
			stack.push_back(n);
		}
		cout<<movement(stack,num)<<endl;
		number--;
	}
}
