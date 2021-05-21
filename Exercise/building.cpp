#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void build(vector<int> F,int n){
	vector<int> area;
	vector<int> color;
	for(int i=0;i<n;i++){
		if(F[i]>0){
			area.push_back(F[i]);
			color.push_back(0);
		}
		else if(F[i]<0){
			area.push_back(abs(F[i]));
			color.push_back(1);
		}
		else break;
	}
//	for(int i=0;i<F.size();i++){
//		cout<<area[i]<<" "<<color[i]<<endl;
//	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(area[i]>area[j]){
				swap(&area[i],&area[j]);
				swap(&color[i],&color[j]);
			}
		}
	}
//	for(int i=0;i<F.size();i++){
//		cout<<area[i]<<" "<<color[i]<<endl;
//	}
//	vector<int> newF;
//	for(int i=0;i<n;i++){
//		if(color[i]==1) newF.push_back(-1*area[i]);
//		else newF.push_back(area[i]);
//	}
//	for(int i=0;i<newF.size();i++){
//		cout<<newF[i]<<endl;
//	}
	int maxfloor=1;
	int pre=color[0];
	for(int i=1;i<n;i++){
		if(color[i]!=pre){
			maxfloor++;
			pre=color[i];
		}
	}
	cout<<maxfloor<<endl;
}
int main(){
	int number;
	cin>>number;
	while(number!=0){
		int num;
		cin>>num;
		vector<int> Floor;
		for(int i=0;i<num;i++){
			int n;
			cin>>n;
			Floor.push_back(n);
		}
		build(Floor,num);
		number--;
	}	
}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//#define pii pair<int,int>//define new object
//#define F first
//#define S second
// 
//int main() {
//    int T, N, n;
//    cin >> T;
//    while (T--) {
//        cin >> N;
//        vector<pii> v;
//        for (int i=0; i<N; i++) {
//            cin >> n;
//            if (n > 0) {
//                v.push_back({n, 1});
//            } else {
//                v.push_back({-n, -1});
//            }
//        }
//        sort(v.begin(), v.end());
//        
//        int pre = v[0].S;
//        int ans = 1;
//        for (int i=1; i<N; i++) {
//            if (v[i].S != pre) {
//                pre = v[i].S;
//                ans++;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}
