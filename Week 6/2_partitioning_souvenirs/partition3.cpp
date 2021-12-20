#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


using namespace std;
using std::vector;

int partition_search(const vector<int>& A, int index,
                      vector<int>& partitions, int target) {
    if (index >= A.size()) return true;
    for (size_t i = 0; i < partitions.size(); i++) {
        if (partitions[i] + A.at(index) <= target) {
            partitions[i] += A.at(index);
            if (partition_search(A, index + 1, partitions, target)) {
                return true;
            }
            partitions[i] -= A.at(index);
        }
    }
    return false;
}


int partition3(vector<int> &A) {
    int n = accumulate(A.begin(), A.end(), 0);
    if (n % 3 != 0 || A.size() < 3 || *max_element(A.begin(), A.end()) > n / 3)
        return 0;

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<int> partitions(3, 0);
    return partition_search(A, 0, partitions, n / 3);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
