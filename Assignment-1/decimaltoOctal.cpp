
#include<iostream>
using namespace std;
int main() {
	int num;
	cin >> num;


	int sb = 8;
	int mul = 1;
	int ans =0;

	while(num>0){
		int rem =num%8;
		ans+=(rem*mul);
        mul = mul * 10;
		num = num/sb;
	}
	cout << ans;
}