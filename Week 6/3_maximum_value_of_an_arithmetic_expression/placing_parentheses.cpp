#include <iostream>
#include <cassert>
#include <string>
#include <vector>

typedef long long ll;
using namespace std;
using std::vector;
using std::string;
using std::max;
using std::min;


long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
    size_t n = (exp.size() + 1) / 2;
    vector<pair<ll, ll>> solution(n * n);

    auto get_solution = [&solution, &exp, n](ll i, ll j){
        return solution.at(i * n + j);
    };

    auto set_solution = [&solution, &exp]

  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
