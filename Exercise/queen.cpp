#include <iostream>
#include <vector>
using namespace std;
void judge(vector<int> p){
	int deltaX,deltaY;
	deltaX=p[2]-p[0]; 
	deltaY=p[3]-p[1];
	if((deltaX!=deltaY&&deltaX!=-deltaY)&&(deltaX!=0&&deltaY!=0)) cout<<"False"<<endl;
	else cout<<"True"<<endl;
}
int main() {
	vector<int> po;
	vector<vector<int>> position;
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	while((x1!=0)&&(y1!=0)&&(x2!=0)&&(y2!=0)){
		po.push_back(x1);
		po.push_back(y1);
		po.push_back(x2);
		po.push_back(y2);
		position.push_back(po);
		po.pop_back();
		po.pop_back();
		po.pop_back();
		po.pop_back();
		cin>>x1>>y1>>x2>>y2;
	}
//	for(int i=0;i<position.size();i++)
//		for(int j=0;j<position[i].size();j++)
//			cout<<position[i][j];
	for(int i=0;i<position.size();i++) judge(position[i]);
}
