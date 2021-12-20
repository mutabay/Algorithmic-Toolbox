#include <iostream>
#include <vector>
#include <limits>

#define INFINITE std::numeric_limits<int>::max()
using namespace std;

vector<int> coins{1, 3, 4};
// The minimum number of coins with denominations 1, 3, 4 that changes money.
int get_change(int m) {
    if (m == 0) return 0;

    vector<int> minNumCoins(m+1);
    minNumCoins[0] = 0;

    for (int i = 1; i <= m; ++i) {
        minNumCoins[i] = INFINITE;
        for (int coin : coins) {
            if (i >= coin)
            {
                int numCoins = minNumCoins[i - coin];
                if (numCoins != INFINITE && numCoins + 1 < minNumCoins[i])
                    minNumCoins[i] = numCoins + 1;
            }
        }
    }

    if (minNumCoins[m] == INFINITE)
        return -1 ;

    return minNumCoins[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
