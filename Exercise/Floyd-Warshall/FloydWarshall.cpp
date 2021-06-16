#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int numofvertex,numofpath,value;
	char start,end;
	int inf=9999; //refers to infinity (because there are few points and paths in the question, 9999 is enough for solving the problem)
	cin>>numofvertex>>numofpath;//There are n points and m paths (one point represents a city)
	string s="INF";
	int FWd[numofvertex][numofvertex];
	// Adjacent matrix storage method (create a two-dimensional array to store point-to-point path information)
	for (int i=0;i<numofvertex;i++)
	{
		for (int j=0;j<numofvertex;j++)
		{
			if (i==j)
			{
				FWd[i][j]=0;
			}
			else FWd[i][j]=inf;
		}
	}
	vector <char> vertices;
	 //Read the path information between points and points
	for (int i=0;i<numofpath;i++)
	{
		cin>>start>>end>>value;
		
		vector<char>::iterator it1=find(vertices.begin(), vertices.end(), start); //find start
		if (it1==vertices.end()) vertices.push_back(start) ;
		
		vector<char>::iterator it2=find(vertices.begin(), vertices.end(), end); //find end
		if (it2==vertices.end()) vertices.push_back(end) ;
		
		vector<char>::iterator it3=find(vertices.begin(), vertices.end(), start); //find start again
		vector<char>::iterator it4=find(vertices.begin(), vertices.end(), end); //find end again
		FWd[distance(vertices.begin(), it3)][distance(vertices.begin(), it4)]=value; //change distance in matrix
	}
	 //Core statement of Floyd-Warshall algorithm
	for (int k=0;k<numofvertex;k++)
	{
		for (int i=0;i<numofvertex;i++)
		{
			for (int j=0;j<numofvertex;j++)
			{
				if (FWd[i][k]<inf && FWd[k][j]<inf && FWd[i][j]>FWd[i][k]+FWd[k][j])
				{
					 FWd[i][j]=FWd[i][k]+FWd[k][j];//Update the shortest path from point i to point j
				}
			}
		}
	}
	 //Result output
	for (int i=0;i<numofvertex;i++)
	{
		for (int j=0;j<numofvertex;j++)
		{	
			if(j==numofvertex-1){
				if(FWd[i][j]==inf) cout<<s;
				else cout<<FWd[i][j];
			}
			else {
				if(FWd[i][j]==inf) cout<<s<<' ';
				else cout<<FWd[i][j]<<' ';
			}
		}
		cout<<endl; 
	}
} 

