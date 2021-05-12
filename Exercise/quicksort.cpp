#include <iostream>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int *number,int size,int first,int last){
    int i, j, pivot;
	if(first>=last) return;
  	pivot=first;
 	i=first+1;
  	j=last;
  	while(true){
        while(i<=last&&number[i]<=number[pivot])
        	i++;
       	while(j>first&&number[j]>number[pivot])
       		j--;
     	if(i>j) break;
     	swap(&number[i], &number[j]);
     	for (int k = 0; k < size; k++) cout << number[k] << " ";
		cout  << endl;
  	}
	swap(&number[j], &number[first]);
	for (int k = 0; k < size; k++) cout << number[k] << " ";
	cout << endl;
 	quicksort(number,size,first,j-1);
  	quicksort(number,size,j+1,last);
}
int main() {
    int n;
    cin >> n;
    int arr[n] ;
    for(int i = 0; i < n; i++) cin >> arr[i]; 
	for (int k = 0; k < n; k++) cout << arr[k] << " ";
	cout << endl;
    quicksort(arr,n ,0, n-1);
}



