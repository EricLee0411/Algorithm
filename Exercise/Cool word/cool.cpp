#include<iostream>
#include <vector>
using namespace std;
int cold(string s){
	vector<int> letters;
	for(int i=0;i<s.size();i++){
		int time=1;
		for(int j=i+1;j<s.size();j++){
			if(s[i]==s[j]&&s[i]!='0'&&s[j]!='0'){
				time++;
				s[j]='0';
			}
		}
		if(s[i]!='0') letters.push_back(time);//cout<<time<<" ";
	}
	int result=1;
	if(letters.size()==1) result=0;
	else{
		for(int i=0;i<letters.size()-1;i++){
			for(int j=i+1;j<letters.size();j++){
				if(letters[i]==letters[j]){
					result=0;
				}
			}
		}
	}
	return result;
}
int main(){
	int number;
	int k=1;
	cin>>number;
	while(number!=0){
		int num,coldtime=0;;
		cin>>num;
		while(num!=0){
			string str;
			cin>>str;
			if(cold(str)==1) coldtime++;
			num--;
		}
		cout<<"Case "<<k<<": "<<coldtime<<endl;
		k++;
		number--;
	}
}
