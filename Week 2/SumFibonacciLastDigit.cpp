//
// Created by tyyp- on 10/13/2021.
//
#include <iostream>

typedef long long ll;
using namespace std;


int FindSumFibonacciNumberLastDigit(ll n)
{
    if (n <= 1) return n;

    long long previous = 0;
    long long current = 1;
    long long res_sum = 1, seq_sum = 1;
    long long tmp_previous = 0;

    for (long long i = 0; i < 59; ++i) {
        tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        seq_sum = (seq_sum + current) % 10;
        if (i < (n - 1) % 60) {
            res_sum = (res_sum + current) % 10;
        }
    }
    return (seq_sum * (n / 60) % 10 + res_sum) % 10;
}

int main() {
    ll n;
    cin >> n;
    ll fibNumber = FindSumFibonacciNumberLastDigit(n);
    cout << fibNumber << endl;

    return 0;
}
