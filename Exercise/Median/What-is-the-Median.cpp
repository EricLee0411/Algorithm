#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> seq;
	while(n!=0){
		int s;
		cin>>s;
		seq.push_back(s);
		sort(seq.begin(), seq.end());
		if(seq.size()%2==0){
			cout<<(seq[seq.size()/2]+seq[seq.size()/2-1])/2<<endl;
		}
		else{
			cout<<seq[(seq.size()-1)/2]<<endl;
		}
		n--;
	}
}
