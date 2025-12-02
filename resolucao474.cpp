#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return solve(strs, 0, m, n);
    }

    int solve(vector<string>& strs, int index, int m, int n) {
        if (index == strs.size()) return 0;

        int zeros = 0, ones = 0;
        for (char c : strs[index]) {
            if (c == '0') zeros++;
            else ones++;
        }

        // não pegar
        int best = solve(strs, index + 1, m, n);

        // pegar 
        if (zeros <= m && ones <= n) {
            best = max(best, 1 + solve(strs, index + 1, m - zeros, n - ones));
        }

        return best;
    }
};
