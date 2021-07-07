#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;


int main () {
    int n;
    cin >> n;
    int arr [n];
    for( int i = 0; i < n ; i++ ){
        cin >> arr[i];
    }
	sort(arr,arr+n);
    // for( int i = 0; i < n;i++){
    //     cout << arr[i] << endl;
    // }
	int count = 0;
	for(int i = n -1; i >= 2; i++){
		int s = 0;
		int e = i - 1;
		while(s < e){
			if(arr[s]+ arr[e] > arr[i]){
				count += (e-s);
				e--;
			}
			else{
				s++;
			}
		}
	}
    cout << count << endl;
    
}