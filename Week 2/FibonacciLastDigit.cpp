//
// Created by tyyp- on 10/13/2021.
//
#include <iostream>
#include <vector>
using namespace std;

long long FindFibonacciNumberLastDigit(int n)
{
    vector<long long> fibSequence{0,1};
    for (int i = 2; i <= n; ++i)
        fibSequence.insert(fibSequence.begin() + i,(fibSequence[i - 1] + fibSequence[i - 2] ) % 10) ;

    return fibSequence[n % 60];
}

int main() {
    long long n;
    cin >> n;
    long long fibNumber = FindFibonacciNumberLastDigit(n);
    cout << fibNumber << endl;

    return 0;
}
