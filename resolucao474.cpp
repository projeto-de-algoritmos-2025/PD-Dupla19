#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        int L = strs.size();
        vector<vector<vector<int>>> dp(
            L + 1,
            vector<vector<int>>(m + 1, vector<int>(n + 1, 0))
        );

        // pr-conta zeros e uns
        vector<pair<int,int>> count(L);
        for (int i = 0; i < L; i++) {
            int zeros = 0, ones = 0;
            for (char c : strs[i]) {
                if (c == '0') zeros++;
                else ones++;
            }
            count[i] = {zeros, ones};
        }

        for (int i = 1; i <= L; i++) {
            int z = count[i - 1].first;
            int o = count[i - 1].second;

            for (int mm = 0; mm <= m; mm++) {
                for (int nn = 0; nn <= n; nn++) {
                    // não pegar
                    dp[i][mm][nn] = dp[i - 1][mm][nn];

                    // pegar 
                    if (mm >= z && nn >= o) {
                        dp[i][mm][nn] = max(
                            dp[i][mm][nn],
                            1 + dp[i - 1][mm - z][nn - o]
                        );
                    }
                }
            }
        }

        return dp[L][m][n];
    }
};
