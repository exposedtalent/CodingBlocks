/* C++ program to find roots of a quadratic equation */
#include<iostream>
#include<math.h>

using namespace std;
 
// Prints roots of quadratic equation ax*2 + bx + x
void findRoots(int a, int b, int c)
{
    // If a is 0, then equation is not quadratic, but
    // linear
    if (a == 0) {
        cout << "Invalid";
        return;
    }
 
    int d = b * b - 4 * a * c;
    double sqrt_val = sqrt(abs(d));
 
    if (d > 0) {
        cout << "Real and Distinct\n";
        cout << (double)(-b + sqrt_val) / (2 * a) << "\n"
             << (double)(-b - sqrt_val) / (2 * a);
    }
    else if (d == 0) {
        cout << "Real and Equal\n";
        cout << -(double)b / (2 * a);
    }
    else // d < 0
    {
        cout << "Imaginary \n";
        cout << -(double)b / (2 * a) << " + i" << sqrt_val
             << "\n"
             << -(double)b / (2 * a) << " - i" << sqrt_val;
    }
}
 
// Driver code
int main()
{

    int a, b , c ;
    cin >> a >> b >> c;
    // Function call
    findRoots(a, b, c);
    return 0;
}