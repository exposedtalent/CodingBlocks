/* 
    Given an array of n int, design aan O(n) lago otoo obuild a max heap
*/
#include<iostream>
#include<queue>

using namespace std;

int main(){
    int arr[]= {-1,5,4,0,1,2,3};
    int n = sizeof(arr)/ sizeof(int);
    for(int i  = n/2; i >= 1; i--){
        hepify(arr,n,i);
    }  
    return 0;
}