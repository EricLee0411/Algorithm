#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double rounding(double num, int index)
{
    bool isNegative = false; // whether is negative number or not
	
    if(num < 0) // if this number is negative, then convert to positive number
    {
        isNegative = true;	
        num = -num;
    }
	
    if(index >= 0)
    {
        int multiplier;
        multiplier = pow(10, index);
        num = (int)(num * multiplier + 0.5) / (multiplier * 1.0);
    }
	
    if(isNegative) // if this number is negative, then convert to negative number
    {
        num = -num;
    }
	
    return num;
}
int main(){
	int n,m;
	cin>>n;
	while(n!=0){
		cin>>m;
		double score[m];
		double total=0;
		for(int i=0;i<m;i++){
			cin>>score[i];
			total+=score[i];
		}
		double avg;
		avg=total/m;
//		cout<<avg<<endl;
		double times=0;
		for(int i=0;i<m;i++){
			if(avg<score[i]) times++;
		}
		double per=times/m;
//		cout<<per<<endl;
		double perc=rounding(per*100, 3);
		cout.setf(ios::fixed);
    	cout<<fixed<<setprecision(3)<<perc<<"%"<<endl;
//		cout<<times<<endl;
		n--;
	}
}
