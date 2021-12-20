#include <iostream>
#include <string>
#include <vector>
#include "limits"

#define INFINITE std::numeric_limits<int>::max();
using namespace std;


int edit_distance(const string &str1, const string &str2) {

    vector<vector<int>> distances;
    int rowCount = str1.size() + 1;
    int colCount = str2.size() + 1;
    distances.resize(rowCount + 1);
    // Preparing distances table
    for (int i = 0; i <= rowCount; ++i) {
        distances[i].resize(colCount + 1);
        for (int j = 0; j <= colCount; ++j) {
            distances[i][0] = i;
            distances[0][j] = j;
        }
    }
    int insertion, deletion, match, mismatch;
    for (int i = 1; i <= rowCount; ++i) {
        for (int j = 1; j <= colCount; ++j) {
            insertion = distances[i][j-1] + 1;
            deletion = distances[i -1][j] + 1;
            match = distances[i - 1][j - 1];
            mismatch = distances[i - 1][j - 1] + 1;
            if (str1[i - 1] == str2[j - 1])
                distances[i][j] = min(insertion, min(deletion, match));
            else
                distances[i][j] = min(insertion, min(deletion, mismatch));
        }
    }
    return distances[rowCount][colCount];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
