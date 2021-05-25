#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findscore(vector<int> s,int r){
	sort(s.begin(),s.end());
	return s[r-1];
}
int main(){
	int number;
	cin>>number;
	while(number!=0){
		vector<int> scores;
		int times=20;
		while(times!=0){
			int score;
			cin>>score;
			scores.push_back(score);
			times--;
		}
		int rank;
		cin>>rank;
		cout<<findscore(scores,rank)<<endl;
		number--;
	}
} 

