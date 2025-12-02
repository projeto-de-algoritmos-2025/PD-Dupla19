#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> matriz(m + 1, vector<int>(n + 1, 0));

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
                    matriz[mm][nn] = max(
                        matriz[mm][nn],
                        1 + matriz[mm - z][nn - o]
                    );
                }
            }
        }

        return matriz[m][n];
    }
};
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> matriz(m + 1, vector<int>(n + 1, 0));

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
                    matriz[mm][nn] = max(
                        matriz[mm][nn],
                        1 + matriz[mm - z][nn - o]
                    );
                }
            }
        }

        return matriz[m][n];
    }
};
