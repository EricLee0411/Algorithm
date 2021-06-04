#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const double esp = 1e-6;
int bestchoice(vector<vector<int> > ps,int n){
	int best=0,gap=0;
	double bestsquarelen=0;
	for(int i=0;i<n;i++){
		if(ps[i][0]>ps[i][1]){
			int temp=ps[i][0];
			ps[i][0]=ps[i][1];
			ps[i][1]=temp;
		}
		double tmpsquarelen;
		if(ps[i][0]==ps[i][1]) tmpsquarelen=ps[i][0]/2.0;
		else{
			if(ps[i][1]/ps[i][0]>=4) tmpsquarelen=ps[i][0];
			else tmpsquarelen=ps[i][0]/2.0;
		}
//		cout<<tmpsquarelen<<endl;
		if(tmpsquarelen>bestsquarelen+esp){
			best++;
			best+=gap;
			bestsquarelen=tmpsquarelen;
			gap=0;
		} 
		else{
			gap++;
		}
//		cout<<best<<endl;
	}
	return best;	
}
int main(){
	int numpapers;
	cin>>numpapers;
	vector<int> bestpaper;
	while(numpapers!=0){
		vector<vector<int>> papers;
		for(int i=0;i<numpapers;i++){
			int len,wid;
			cin>>len>>wid;
			vector<int> paper;
			paper.push_back(len);
			paper.push_back(wid);
			papers.push_back(paper);
		}
//		for(int i=0;i<papers.size();i++){
//			for(int j=0;j<papers[i].size();j++) cout<<papers[i][j]<<endl;
//		}
		bestpaper.push_back(bestchoice(papers,numpapers));
//		cout<<bestchoice(papers,numpapers)<<endl;
		cin>>numpapers;
	}
	for(int i=0;i<bestpaper.size();i++) cout<<bestpaper[i]<<endl;
}
