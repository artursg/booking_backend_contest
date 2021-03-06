#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int factorial(long long int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return n*factorial(n - 1);    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int n,m,c;
    cin >> n >> m >> c;
    cout << factorial(n + m - c - 1) << endl;
    return 0;
}
