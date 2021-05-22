#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int number;
	cin>>number;
	vector<float> v;
	for(int i=0;i<number;i++){
		float num;
		cin>>num;
		v.push_back(num);
	}
 	int answer=0;
	float BoxInside=1.0;
    for(;0<number;)//insure we pick all the things we want to put into box
    {
        for(int j = 0 ; j < number ;j++)
        {
            if(BoxInside-v[j]>-0.01){//use -0.1 because the float number subtraction each other cannot make sure equal to 0
                BoxInside=BoxInside-v[j];
                v.erase(v.begin()+j);//if we had choosen we delete from the vector
                number--;
                break;//use break is make sure we choose from the first things and 
                     //because we use erase so the index may have some problem so we forcibly it run from begin.
            }
            else if(j==number-1)//we caannot put any things into box, then we choose new box to use
            {
                answer+=1;
                BoxInside=1.0;
            }
        }
        if(number==0 && BoxInside<1.0)//because finally our box have nothing to put, so we make check the inside of final box have something or not
        {
            answer+=1;
        }
    }
	cout<<answer<<endl;
}

