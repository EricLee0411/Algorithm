#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
void swap(int *x, int *y) 
	{  
	    int temp=*x; 
	    *x=*y; 
	    *y=temp; 
	} 
void sorted(vector<int> &v){  
    for (int i=0;i<v.size()-1;i++){
		for (int j=0;j<v.size()-i-1;j++){
			if (v[j]>v[j+1]) 
            swap(&v[j],&v[j+1]);  
		}
	}	
}
void printAGES(vector<vector<int>> V){   
	for (int i=0;i<V.size();i++)
    {
        for (int j=0;j<V[i].size();j++)
        {	
			if(j!=V[i].size()-1) cout<<V[i][j]<<" ";
			else cout<<V[i][j];
        }   
        cout<<endl;
    }
}
int main(){
	int number;
	cin>>number;
	vector<vector<int>> AGES;
	while(number!=0){
		vector<int> AGE;
		for(int i=0;i<number;i++){
			int age;
			cin>>age;
			if(0<age&&age<=100) AGE.push_back(age);
		}
		sorted(AGE);
//		sort(AGE.begin(),AGE.end());
		AGES.push_back(AGE);
		cin>>number;
	}
	printAGES(AGES);
}
