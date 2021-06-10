#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 
void addedge(list<int>* g, int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
 
int hamiltonian(list<int>* g, int v, int s, int& count, bool* vis, int& h)
{
    if (count > 1 && s == 0) {
        h = 1;
        return 1;
    }
    list<int>::iterator it;
    for (it = g[s].begin(); it != g[s].end(); it++) {
        if (!vis[*it]) {
            vis[*it] = true;
            count++;
            if (count == v) {
                vis[0] = false;
            }
            hamiltonian(g, v, *it, count, vis, h);
            vis[0] = true;
            vis[*it] = false;
            count--;
        }
    }
    return 0;
}
 
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int v, e;
        cin >> e;
        vector<string> p;
        for(int k=0;k<e;k++){
        	string s;
        	cin>>s;
        	p.push_back(s);
		}
		v=0;
		for(int l=0;l<p.size();l++){
        	if(v<int(p[l][3])) v=int(p[l][3])-48;
		}		
//		cout<<v;
        list<int> g[v];
        int x, y;
        for (int m = 0; m < e; m++) {
        	x=int(p[m][1])-49;
			y=int(p[m][3])-49;
            addedge(g, x, y);
        }
        bool vis[v];
        memset(vis, false, sizeof(vis));
        int count = 1;
        vis[0] = true;
        int h = 0;
        hamiltonian(g, v, 0, count, vis, h);
//        cout << h << endl;
		if(h==1) cout << "True" << endl;
		else cout << "False" << endl;
    }
    return 0;
}

