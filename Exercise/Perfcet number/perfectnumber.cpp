#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int checkperfect(int x){
	int sum=0 ;
	for(int i = 1 ;i <= sqrt(x) ; i++){
		if(x % i == 0){
			if(i == 1) sum = sum + i ;
			else{
				sum = sum + i ;
				if(i != x/i) sum = sum + x/i ;
			}
		}
	}
	if(x==sum) return x;
	else return 0;
}
int main(){
	int n;
	cin>>n;
	vector<int> perf;
	while(n!=0){
		int nums;
		cin>>nums;
		if(checkperfect(nums)!=0) perf.push_back(checkperfect(nums));
		n--;
	}
//	for(auto y : perf)
	for(int i = 0; i < perf.size(); i++) {
		if(i!=perf.size()-1) cout << perf[i] <<" ";
		else cout << perf[i];
    }
}
