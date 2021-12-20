//
// Created by tyyp- on 10/13/2021.
//
#include <iostream>

using namespace std;


int FindGreatestCommonDivisor_Effective(int a, int b)
{
    int bigNumber = a > b ? a : b;
    int smallNumber = a < b ? a : b;
    if (0 == smallNumber)
        return bigNumber;
    return FindGreatestCommonDivisor_Effective(smallNumber, bigNumber % smallNumber);
}

int main() {
    int a,b;
    cin >> a ;
    cin >> b ;
    int gcd = FindGreatestCommonDivisor_Effective(a,b);
    cout << gcd << endl;
    return 0;
}
