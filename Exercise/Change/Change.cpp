#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);//cin.sync_with_stdio(false)是一個“是否兼容stdio”的開關，C++為了兼容C，保正程序在使了std::printf和std::cout的時候不發生混亂，將輸出流綁到了一。也就是 C++標準streams(cin,cout,cerr…)與相應的C標準程序庫文件(stdin,stdout,stderr)同步，使用相同的 stream 緩衝區 
	//默認是同步的，但由於同步會帶來某些不必要的負擔，因此此函數作用是使得用戶可以自行取消同步 
	// cin.tie(NULL) cout.tie(NULL) 取消 cin 和 cout 的綁定。
	int num;
	cin>>num;
	while(num!=0){
		int money, coins, coin[100], minimum[50001] = {};
		cin >> coins >> money;
		if(coins == 0 && money == 0) break; 
		for (int i = 1; i <= money; i++)
			minimum[i] = 50000;
		for (int i = 0; i < coins; i++) {
			cin >> coin[i];
			for (int j = coin[i]; j <= money; j++)
				minimum[j] = min(minimum[j - coin[i]] + 1, minimum[j]);
		}
		cout << minimum[money] << endl;
		num--;
	}
	
}
