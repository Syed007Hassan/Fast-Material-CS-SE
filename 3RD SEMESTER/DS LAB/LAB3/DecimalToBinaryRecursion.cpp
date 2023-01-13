// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
 
// Recursive function to convert n
// to its binary equivalent
void decimalToBinary(int n)
{
    // Base case
    if (n == 0) {
        return;
    }
 
    // Recursive call
    decimalToBinary(n / 2);
    cout << n % 2;
}
 
// Driver code
int main()
{
    int n = 28;
 
    decimalToBinary(n);
 
    return 0;
}
