//
// Created by tyyp- on 10/13/2021.
//

#include <iostream>
typedef long long ll;

using namespace std;

ll CalculatePisanoPeriod(ll m)
{
    ll first = 0;
    ll second = 1;
    ll res = 0;

    for (int i = 0; i < m * m; ++i)
    {
        ll temp = 0;
        temp = second;
        second = (first + second) % m;
        first = temp;

        if (first == 0 && second == 1)
            res = i + 1;
    }
    return res;
}

ll FindFibonacciNumber_Huge(ll n, ll m)
{
    ll pisanoPeriod = CalculatePisanoPeriod(m);
    ll remainder = n % pisanoPeriod;

    ll first = 0;
    ll second = 1;
    ll res = remainder;

    for (int i = 1; i < remainder; ++i)
    {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << FindFibonacciNumber_Huge(n, m) << endl;
    return 0;
}
