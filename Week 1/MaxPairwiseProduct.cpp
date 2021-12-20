#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long maxIndex_1 = -1, maxIndex_2 = -1;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (maxIndex_1 == -1 || numbers[maxIndex_1] < numbers[i] )
            maxIndex_1 = i;                
    }

    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (( maxIndex_2 == -1 || numbers[maxIndex_2] < numbers[i] ) && i != maxIndex_1)
            maxIndex_2 = i;
    }
    
    return numbers[maxIndex_1] * numbers[maxIndex_2];

}

int main() {
    long n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << std::endl;
    return 0;
}
