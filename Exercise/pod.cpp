#include<iostream>
#include<vector>
using namespace std;
void POD(int x){
	vector<int> digits;
	for(int i=9;i>1;i--){
		while(x%i==0){
			digits.push_back(i);
			x/=i;
		}
	}
	//agree 9 to 2(factors).if x's factor are only 2,3,5,7,x=1
	//else x=prime with larger than 10
//	for(int i=0;i<digits.size();i++){
//		cout<<digits[i];
//	}
//	cout<<endl;
//	vector<int>::iterator ptr;

//  	for (ptr = digits.end()-1; ptr!=digits.begin()-1; ptr--)
//        cout << *ptr ;
	if(x!=1) cout<<-1;
	else{
		for(int i=digits.size()-1;i>=0;i--){
			cout<<digits[i];
		}
		//print from end to begin since final element of digits vector is ­Ó¦ì¼Æ 
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	while(n!=0){
		int num;
		cin>>num;
//	if(num<0||num>1000000000){
//		cout<<-1<<endl;
//		cin>>num;
//	} 
		if(0<=num<=1000000000){
			if(num==0||num==1) cout<<num<<endl;
			else POD(num);
		}
		n--;
	}
	
}
