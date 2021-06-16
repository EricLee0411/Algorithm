#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int maxnum=1005;
string s1, s2;
int dp[maxnum][maxnum];
 
int main() {
	int num;
	cin>>num;
    int l1, l2;
    while (num!=0) {
		cin >> s1 >> s2;
        l1 = s1.length();
        l2 = s2.length();
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<l1; i++) {
            for (int j=0; j<l2; j++) {
                if (s1[i] == s2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        cout << dp[l1][l2] << endl;
        num--;
    }
    return 0;
} 
