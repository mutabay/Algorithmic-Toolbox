//#include <iostream>
//#include <vector>
//
//typedef long long ll;
//
//using namespace std;
//// Effective Way
//vector<int> FindFibonacciNumber(int n)
//{
//    vector<int> fibSequence{0,1};
//    for (int i = 2; i <= n; ++i)
//        fibSequence.insert(fibSequence.begin() + i,fibSequence[i - 1] + fibSequence[i - 2] ) ;
//
//    return fibSequence;
//}
//
//// Naive Way
//int FindFibonacciNumberRecursive(int n)
//{
//    if (n <= 1)
//        return n;
//    return FindFibonacciNumberRecursive(n - 1) + FindFibonacciNumberRecursive(n - 2);
//}
//
//int FindGreatestCommonDivisor_Naive(int a, int b)
//{
//    int gcd = 0;
//    int bigNumber = a > b ? a : b;
//    for (int i = 1; i <= bigNumber; ++i) {
//        if (a % i == 0 && b % i == 0)
//            gcd = i;
//    }
//    return gcd;
//}
//
//int FindGreatestCommonDivisor_Effective(int a, int b)
//{
//    int bigNumber = a > b ? a : b;
//    int smallNumber = a < b ? a : b;
//    if (0 == smallNumber)
//        return bigNumber;
//    return FindGreatestCommonDivisor_Effective(smallNumber, bigNumber % smallNumber);
//}
//
//ll FindLeastCommonMultiple_Effective(ll a, ll b)
//{
//    return (a*b) / FindGreatestCommonDivisor_Effective(a, b);
//}
//
//ll CalculatePisanoPeriod(ll m)
//{
//    ll first = 0;
//    ll second = 1;
//    ll res = 0;
//
//    for (int i = 0; i < m * m; ++i)
//    {
//        ll temp = 0;
//        temp = second;
//        second = (first + second) % m;
//        first = temp;
//
//        if (first == 0 && second == 1)
//            res = i + 1;
//    }
//    return res;
//}
//
//ll FindFibonacciNumber_Huge(ll n, ll m)
//{
//    ll pisanoPeriod = CalculatePisanoPeriod(m);
//    ll remainder = n % pisanoPeriod;
//
//    ll first = 0;
//    ll second = 1;
//    ll res = remainder;
//
//    for (int i = 1; i < remainder; ++i)
//    {
//        res = (first + second) % m;
//        first = second;
//        second = res;
//    }
//
//    return res % m;
//}
//int main() {
////    vector<int> fibSequence = FindFibonacciNumber(6);
////    for (auto number :fibSequence) {
////        cout << number << " ";
////    }
////    cout << endl;
////    cout << FindFibonacciNumberRecursive(10);
//
////    int gcd = FindGreatestCommonDivisor_Naive(8,24);
////    cout << "gcd = " << gcd << endl;
//
////    int gcd = FindGreatestCommonDivisor_Effective(24,8);
////    cout << "gcd = " << gcd << endl;
////
////
////    ll n, m;
////    cin >> n >> m;
////    cout << FindFibonacciNumber_Huge(n, m) << endl;
//
//
//
//    return 0;
//}

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
