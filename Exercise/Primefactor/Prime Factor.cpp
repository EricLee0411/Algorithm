#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> factor;
	vector<int> expotent;
	for(int i=2;i<=n;i++){
		if(n%i==0){
			int r=i-1;
			int m=i%r;
			while(m!=0){
				r--;
				m=i%r;
			}
			if(m==0&&r==1) factor.push_back(i);
		}
	}
//	for(int i=0;i<factor.size();i++){
//		cout<<factor[i];
//	}
//	cout<<endl;
	for(int i=0;i<factor.size();i++){
		int e=0;
		int p=n%factor[i];
		int d=n;
		while(p==0){
			e++;
			d/=factor[i];
			p=d%factor[i];
		}
		expotent.push_back(e);
	}
//	for(int i=0;i<expotent.size();i++){
//		cout<<expotent[i];
//	}
//	cout<<endl;
	string primefactor="";
	for(int i=0;i<factor.size();i++){
		if(i!=factor.size()-1){
			if(expotent[i]==1){
				primefactor+=to_string(factor[i]);
				primefactor+="*";
			}
			else{
				primefactor+=to_string(factor[i]);
				primefactor+="^";
				primefactor+=to_string(expotent[i]);
				primefactor+="*";
			}
		}
		else{
			if(expotent[i]==1){
				primefactor+=to_string(factor[i]);
			}
			else{
				primefactor+=to_string(factor[i]);
				primefactor+="^";
				primefactor+=to_string(expotent[i]);
			}
		}
	}
	cout<<n<<"="<<primefactor<<endl;
}

