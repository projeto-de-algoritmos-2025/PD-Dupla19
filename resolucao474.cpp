#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // pre-conta zeros e uns
        vector<pair<int,int>> count;
        for (string &s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }
            count.push_back({zeros, ones});
        }

        // atualizar de trás pra frente
        for (auto &p : count) {
            int z = p.first;
            int o = p.second;

            for (int mm = m; mm >= z; mm--) {
                for (int nn = n; nn >= o; nn--) {
                    dp[mm][nn] = max(
                        dp[mm][nn],
                        1 + dp[mm - z][nn - o]
                    );
                }
            }
        }

        return dp[m][n];
    }
};
