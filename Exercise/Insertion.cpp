#include<iostream>
#include<vector>
using namespace std; 
int swaptimes(vector<int> s){
	int time=0;
	for (int i=1;i<s.size(); i++) {
        int key=s[i];
        int j=i-1;
        while(key<s[j]&&j>=0) {
            s[j+1]=s[j];
            time++;
            j--;
        }
        s[j+1]=key;
    }
    return time;
}
int main(){
	int number;
	cin>>number;
	vector <int> allswaptimes; 
	while(number!=0){
		vector<int> seq;
		for(int i=0;i<number;i++){
			int num;
			cin>>num;
			if(0<=num&&num<=number) seq.push_back(num);
		}
		allswaptimes.push_back(swaptimes(seq));
		cin>>number;
	}
	for (int j=0;j<allswaptimes.size();j++)	
		cout<<"Optimal swapping takes "<<allswaptimes[j]<<" swaps."<<endl;
}
