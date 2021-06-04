#include<iostream>
using namespace std;
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}
int main() {
	int n1,n2;
    // cout << "Enter 2 numbers ";
	cin >> n1 >> n2;
    int data = gcd(n1, n2);
	return data;

}
