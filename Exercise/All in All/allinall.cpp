#include<iostream>
#include <string>
using namespace std;
int main(){
	int number;
	cin>>number;
	while(number!=0){
		string s,t;
		while(cin>>s){
			cin>>t;
			if(s.size()<=t.size()){
				int n=0;
			    bool resalt=true;
				for (int j=0;j<s.size();j++)
			    {
			        for (int i=n;i<t.size();i++)
			        {
			            if (s[j]==t[i])
			            {
			                n=i+1;
			                break;
			            }
			            if (i==t.size()-1) resalt=false;
			        }
			    }
			    if (resalt==true) cout<<"Yes"<<endl;
			    else cout<<"No"<<endl;
			}
			else cout<<"No"<<endl;
		}	
		number--;
	}
}

