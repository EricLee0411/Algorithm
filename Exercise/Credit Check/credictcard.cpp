#include<iostream>
#include<string>
using namespace std;
int main(){
	int numscard;
	cin>>numscard;
	string t;
	getline(cin,t);
	string credictcardnumber;
	while(numscard!=0){
		getline(cin,credictcardnumber);
		string temp;
		for(int i=0;i<credictcardnumber.length();i++) 
			if(credictcardnumber[i]!=' ') temp+=credictcardnumber[i];
	//	cout<<temp; 
		int valid=0;
		for(int i=0;i<temp.length();i++){
			if(i%2==0){
				int tmp=(2*(int(temp[i])-48))/10+(2*(int(temp[i])-48))%10;
	//			cout<<tmp<<endl; 
				valid+=tmp;
			}
			else valid+=(int(temp[i])-48);
		} 
	//	cout<<valid<<endl;
		if(valid%10==0) cout<<"Valid"<<endl;
		else cout<<"Invalid"<<endl;
		numscard--;
	}
	
} 
