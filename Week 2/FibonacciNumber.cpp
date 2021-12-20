//
// Created by tyyp- on 10/13/2021.
//

#include <iostream>
#include <vector>
using namespace std;

long long FindFibonacciNumber(int n)
{
    vector<long long> fibSequence{0,1};
    for (int i = 2; i <= n; ++i)
        fibSequence.insert(fibSequence.begin() + i,fibSequence[i - 1] + fibSequence[i - 2] ) ;

    return fibSequence[n];
}

int main() {
    long long n;
    cin >> n;
    long long fibNumber = FindFibonacciNumber(n);
    cout << fibNumber << endl;

    return 0;
}
