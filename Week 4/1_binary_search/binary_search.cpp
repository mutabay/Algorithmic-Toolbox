#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int) a.size();
    //write your code here
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid] == x)
            return mid;
        else if (a[mid] <= x)
            left = mid + 1;
        else if (a[mid] > x)
            right = mid - 1;
    }
    return -1;

}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n = 2;
  vector<int> b = {1,2,3,4,5};
  std::cout << binary_search(b, n) << std::endl;
}
