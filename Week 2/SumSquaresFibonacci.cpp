//
// Created by tyyp- on 10/14/2021.
//

//
// Created by tyyp- on 10/13/2021.
//

#include <iostream>
typedef long long ll;

using namespace std;

ll CalculateSumSquareFibonacci(ll to)
{
    if (to <= 1) return to;

    bool flag = false;
    long long previous = 0;
    long long current = 1;
    long long tmp_previous = 0;

    long long seq_sum = 1;

    for (long long i = 2; i < 60; ++i) {
        tmp_previous = current;
        current = (previous + current) % 10;
        previous = tmp_previous;
        seq_sum = (seq_sum + current * current) % 10;
    }

    seq_sum = (seq_sum * ((to / 60) % 10)) % 10;

    previous = 0;
    current = 1;
    tmp_previous = 0;
    for (size_t i = 0; i < 60; i++) {
        if (i <= 1 and i <= to % 60)
            seq_sum = (seq_sum + i) % 10;
        else if (i <= to % 60) {
            tmp_previous = current;
            current = (current + previous) % 10;
            previous = tmp_previous;
            seq_sum = (seq_sum + current * current) % 10;
        }
    }
    return seq_sum;
}
int main() {
    ll n;
    cin >> n;
    cout << CalculateSumSquareFibonacci(n) << endl;
    return 0;
}
