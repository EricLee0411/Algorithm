#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);//cin.sync_with_stdio(false)�O�@�ӡ��O�_�ݮestdio�����}���AC++���F�ݮeC�A�O���{�Ǧb�ϤFstd::printf�Mstd::cout���ɭԤ��o�ͲV�áA�N��X�y�j��F�@�C�]�N�O C++�з�streams(cin,cout,cerr�K)�P������C�зǵ{�Ǯw���(stdin,stdout,stderr)�P�B�A�ϥάۦP�� stream �w�İ� 
	//�q�{�O�P�B���A���ѩ�P�B�|�a�ӬY�Ǥ����n���t��A�]������Ƨ@�άO�ϱo�Τ�i�H�ۦ�����P�B 
	// cin.tie(NULL) cout.tie(NULL) ���� cin �M cout ���j�w�C
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
