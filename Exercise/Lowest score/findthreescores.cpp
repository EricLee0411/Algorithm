#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int,int>//define new object
#define F first
#define S second
string alternation(int n){
	string N;
	if(n==0) N="A";
	else N="B";
	return N;
}
void findthreescores(vector<pii> s){
	cout<<alternation(s[0].S)<<alternation(s[1].S)<<alternation(s[2].S)<<endl;
}
int main()
{
	int number;
	cin>>number;
	while(number!=0){
		int numofstudent;
		cin>>numofstudent;
		vector<pii> scores;
		int score,prescore=-1;
		while(numofstudent!=0){
			cin>>score;
			if(score>=prescore){
				scores.push_back({score,0});
				if(prescore!=101) prescore=score;
			} 
			else{
				scores.push_back({score,1});
				prescore=101;
			}
			numofstudent--;
		}
		sort(scores.begin(), scores.end());
		findthreescores(scores);
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
