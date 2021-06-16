#include<iostream>
using namespace std;
bool check(char point_match[],char k,int maxs){
    for(int i=0;i<maxs;i++){
        if(k==point_match[i]){
            return false;
        }
    }
    return true;
}
int check_point(char point_match[],char k,int maxs){
    for(int i=0;i<maxs;i++){
        if(point_match[i]==k){
            return i;
        }
    }
}
int mines(int point[],bool exist[],int maxs){
    int mins=99999,mini;
    for(int i=0;i<maxs;i++){
        if(exist[i]==false && point[i]<mins){
            mins=point[i];
            mini=i;
        }
    }
    return mini;
}
int dij(int start,int ends,int **graph,int maxs){
    bool exist[maxs];
    int point[maxs];
    for(int i=0;i<maxs;i++){
        exist[i]=false;
        point[i]=99999;
    }
    point[start]=0;
    for(int i=0;i<maxs-1;i++){
        int mins=mines(point,exist,maxs);
        exist[mins]=true;
        for(int j=0;j<maxs;j++){
            if(exist[j]==false && point[mins]!=99999 && graph[mins][j] && point[j]>point[mins]+graph[mins][j]){
                point[j]=point[mins]+graph[mins][j];
            }
        }
    }
    return point[ends];
}
int main(){
    char as[2];
    int times;
    cin>>as[0]>>as[1];
    cin>>times;
    char edge[times][2];
    int edge_number[times];
    int point[26];
    for(int i=0;i<26;i++){
        point[i]=0;
    }
    for(int i=0;i<times;i++){
        cin>>edge[i][0]>>edge[i][1];
        cin>>edge_number[i];
        point[int(edge[i][0])-97]=1;
        point[int(edge[i][1])-97]=1;
    }
    int point_number=0;
    for(int i=0;i<26;i++){
        if(point[i]==1){
            point_number++;
        }
    }
    int p=0;
    char point_match[point_number]={' '};
    for(int i=0;i<times;i++){
        if(check(point_match,edge[i][0],point_number)){
            point_match[p]=edge[i][0];
            p++;
        }
        if(check(point_match,edge[i][1],point_number)){
            point_match[p]=edge[i][1];
            p++;
        }
    }
    int graph[point_number][point_number];
    for(int i=0;i<point_number;i++){
        for(int j=0;j<point_number;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<times;i++){
        graph[check_point(point_match,edge[i][0],point_number)][check_point(point_match,edge[i][1],point_number)]=edge_number[i];
    }
    int *graphs[point_number];
    for(int i=0;i<point_number;i++){
        graphs[i]=graph[i];
    }
    int answer;
    answer=dij(check_point(point_match,as[0],point_number),check_point(point_match,as[1],point_number),graphs,point_number);
    cout<<answer<<endl;
}
