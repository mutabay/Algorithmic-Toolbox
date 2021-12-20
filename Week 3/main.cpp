#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>



#define SENTINEL_VALUE (-1)
typedef long long ll;

using namespace std;

//  changing money with a minimum number of coins;
// Task 1
//int GetChange(int m)
//{
//    int change = 0;
//    int factor = 1;
//    vector<int> coins{10, 5, 1};
//    for (int coin : coins) {
//        if (m == 0)
//            return change;
//        if (coin <= m)
//        {
//            factor = m / coin;
//            m -= coin * factor;
//            change += factor * 1;
//        }
//    }
//    return change;
//}


// Task 2
//double GetOptimalValue(int capacity, vector<double> weights, vector<double> values)
//{
//    double value = 0;
//    vector<double> valueRates(weights.size());
//    int maxElementIndex = 0;
//    for (int i = 0; i < weights.size(); ++i)
//        valueRates[i] = values[i]/ weights[i];
//
//    for (double valueRate: valueRates) {
//        maxElementIndex = max_element(valueRates.begin(), valueRates.end()) - valueRates.begin();
//        if(capacity == 0)
//            return value;
//        if(weights[maxElementIndex] != 0)
//        {
//            int limit = min((double)capacity, weights[maxElementIndex]);
//            value += valueRates[maxElementIndex] * limit;
//            capacity -= limit;
//            weights[maxElementIndex] -= limit;
//        }
//        if (weights[maxElementIndex] == 0)
//            valueRates[maxElementIndex] = SENTINEL_VALUE;
//
//    }
//    return value;
//}

// Task 3
//int ComputeMinRefills(int dist, int tank, vector<int> & stops)
//{
//    stops.insert(stops.begin(), 0);
//    stops.push_back(dist);
//    int numRefills = 0;
//    int currRefill = 0;
//    int lastRefill;
//    if(tank > dist)
//        return 0;
//    while(currRefill < stops.size())
//    {
//        lastRefill = currRefill;
//        while( currRefill < stops.size()  && (stops[currRefill + 1] - stops[lastRefill]) <= tank)
//            currRefill++;
//        if(currRefill < stops.size() )
//            numRefills++;
//        if(currRefill == lastRefill)
//            return SENTINEL_VALUE;
//    }
//    return numRefills;
//}

// Task 4
//ll MaxDotProduct(vector<ll> a, vector<ll> b)
//{
//    sort(a.begin(),a.end(), greater<ll>());
//    sort(b.begin(),b.end(), greater<ll>());
//    ll result = 0;
//    for (int i = 0; i < a.size(); ++i)
//        result += a[i] * b[i];
//
//    return result;
//}


// Task 4
struct Segment {
    int start, end;
};

vector<int> OptimalPoints(vector<Segment> &segments) {
    vector<int> points;
    //write your code here
    for (size_t i = 0; i < segments.size(); ++i) {
        points.push_back(segments[i].start);
        points.push_back(segments[i].end);
    }
    return points;
}

int main() {
// - Task 1
//    int m;
//    std::cin >> m;
//    std::cout << GetChange(m) << '\n';

// - Task 2
//    int capactiy,n;
//    cin >> n >> capactiy;
//    vector<double> values(n);
//    vector<double> weights(n);
//    for (int i = 0; i < n; i++) {
//        std::cin >> values[i] >> weights[i];
//    }
//    double value = GetOptimalValue(capactiy, weights, values);
//    cout << value;

// - Task 3
//    int dist, tank, stopCount;
//    cin >> dist >> tank >> stopCount;
//    vector<int> stops(stopCount);
//    for (int i = 0; i < stopCount; ++i)
//        cin >> stops[i];
//
//    int optimalNumRefills =ComputeMinRefills(dist, tank,stops  ) ;
//    cout << optimalNumRefills;

// - Task 4
//    int addNumber;
//    cin >> addNumber;
//    vector<ll> a(addNumber);
//    vector<ll> b(addNumber);
//    for (int i = 0; i < addNumber; ++i)
//        cin >> a[i];
//    for (int i = 0; i < addNumber; ++i)
//        cin >> b[i];
//    ll dotProduct = MaxDotProduct(a,b);
//    cout << dotProduct;

// - Task 5
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = OptimalPoints(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }

    return 0;
}
