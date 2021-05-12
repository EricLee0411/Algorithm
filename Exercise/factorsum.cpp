#include <iostream>
#include <cmath>
using namespace std ;
int main(){
	int m = 0 ;
	int n ;
	cin >> n ;
	for(int i = 1 ;i <= sqrt(n) ; i++){
		if(n % i == 0){
			if(i == 1) m = m + i ;
			else{
				m = m + i ;
				if(i != n/i) m = m + n/i ;
			}
		}
	}
	cout<<m<<endl;
}
