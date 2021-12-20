
//
// Created by tyyp- on 10/13/2021.
//
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;


ll FindPartialSumFibonacci(ll from, ll to)
{
    if (to < from) return 0;
    vector<long> vec(60);
    long long previous = 0;
    long long current = 1;
    long long tmp_previous = 0;

    long long seq_sum = 1;

    vec[0] = 0;
    vec[1] = 1;

    for (long long i = 2; i < 60; ++i) {
        tmp_previous = current;
        current = (previous + current) % 10;
        previous = tmp_previous;
        seq_sum = (seq_sum + current) % 10;
        vec[i] = current;
    }
    seq_sum = (seq_sum * (((to - from + 1) / 60) % 10)) % 10;

    if (from / 60 == to / 60) {
        for (size_t i = from % 60; i <= to % 60; i++) {
            seq_sum = (seq_sum + vec.at(i)) % 10;
        }
    } else if (from / 60 < to / 60) {
        for (size_t i = 0; i < 60; i++) {
            if (i >= from % 60) {
                seq_sum = (seq_sum + vec.at(i)) % 10;
            }
            if (i <= to % 60) {
                seq_sum = (seq_sum + vec.at(i)) % 10;
            }
        }
    }
    return seq_sum;
}
int main() {
    ll from, to;
    cin >> from >> to;
    cout << FindPartialSumFibonacci(from,to) << endl;

    return 0;
}
