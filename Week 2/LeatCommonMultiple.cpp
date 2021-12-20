//
// Created by tyyp- on 10/13/2021.
//
#include <iostream>

typedef long long ll;


ll FindGreatestCommonDivisor_Effective(ll a, ll b)
{
    ll bigNumber = a > b ? a : b;
    ll smallNumber = a < b ? a : b;
    if (0 == smallNumber)
        return bigNumber;
    return FindGreatestCommonDivisor_Effective(smallNumber, bigNumber % smallNumber);
}

ll FindLeastCommonMultiple_Effective(ll a, ll b)
{
    return (a*b) / FindGreatestCommonDivisor_Effective(a, b);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << FindLeastCommonMultiple_Effective(a, b) << std::endl;
    return 0;
}

