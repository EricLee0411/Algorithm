#include<iostream>
#include<vector>
using namespace std;
int MaxDivide(int x, int y)//let x=x/y untill the factor of x don't have any y
{
    while (x % y == 0)
        x = x / y;
    return x;
}
int IsUgly(int num)
{
    num = MaxDivide(num, 2);
    num = MaxDivide(num, 3);
    num = MaxDivide(num, 5);
 
    return (num == 1) ? 1 : 0;//30/2=15->15/3=5->5/5=1=num->initial num's factors are 2,3,5->uglynumber
}
int GetNthUglyNo(int order)
{
    
    int i = 1;
    int count = 1;// ugly number count
    while (order > count) {// Check for all integers untill ugly count becomes order
        i++;
        if (IsUgly(i))
            count++;
    }
    return i;//true number
}
int main(){
	int n;
	cin>>n;
	while(n!=0){
		int N;
		cin>>N;
		cout<<GetNthUglyNo(N)<<endl;
		n--;
	}
}
